//
// Created by 高翔 on 2017/12/15.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <chrono>
#include <cmath>

using namespace std;
using namespace Eigen;

double func_R(double xr,double ar,double br,double cr) {
    return exp(ar*xr*xr+br*xr+cr);
}

double func_E(double xe,double ae,double be,double ce){
    return std::exp(ae*ae*xe+be*xe+ce);
}

int main(int argc, char **argv) {
    double ar = 1.0, br = 2.0, cr = 1.0;         // 真实参数值
    double ae = 2.0, be = -1.0, ce = 5.0;        // 估计参数值
    int N = 100;                                 // 数据点
    double w_sigma = 1.0;                        // 噪声Sigma值
    double inv_sigma=1.0/w_sigma;
    cv::RNG rng;                                 // OpenCV随机数产生器

    vector<double> x_data, y_data;      // 数据
    for (int i = 0; i < N; i++) {
        double x = i / 100.0;
        x_data.push_back(x);
        y_data.push_back(exp(ar * x * x + br * x + cr) + rng.gaussian(w_sigma));
    }

    // 开始Gauss-Newton迭代
    int iterations = 100;    // 迭代次数
    double cost = 0, lastCost = 0;  // 本次迭代的cost和上一次迭代的cost

    //计时开始
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    //开始迭代
    for (int iter = 0; iter < iterations; iter++) {

        Matrix3d H = Matrix3d::Zero();             // Hessian = J^T J in Gauss-Newton
        Vector3d b = Vector3d::Zero();             // bias
        cost = 0;

        for (int i = 0; i < N; i++) {
            double xi = x_data[i], yi = y_data[i];  // 第i个数据点
            // start your code here
            double error = 0.00;   // 第i个数据点的计算误差
            error =yi-exp(ae*xi*xi+be*xi+ce); // 填写计算error的表达式
            Vector3d J; // 雅可比矩阵  列向量
            J[0] = -xi*xi*exp(ae*xi*xi+be*xi+ce);  // de/da
            J[1] = -xi*exp(ae*xi*xi+be*xi+ce);  // de/db
            J[2] = -exp(ae*xi*xi+be*xi+ce);  // de/dc

            H += J * J.transpose(); // GN近似的H 3*3
            b += -error * J; //列向量

//            H += inv_sigma * inv_sigma * J * J.transpose();//和自己写的不一样
//            b += -inv_sigma * inv_sigma * error * J;//和自己写的不一样
            // end your code here

            cost += error * error;
        }

        // 求解线性方程 Hx=b，建议用ldlt
 	// start your code here
        Vector3d dx;//增量x
        dx=H.ldlt().solve(b);//ldlt解决H*dx=b的问题

	// end your code here

        if (isnan(dx[0])) {//数据为正负无穷或任意实数，isnan返回false
            cout << "result is nan!" << endl;
            break;
        }

        if (iter > 0 && cost > lastCost) {
            // 误差增长了，说明近似的不够好
            cout << "cost: " << cost << ", last cost: " << lastCost << endl;
            break;
        }

        // 更新abc估计值
        ae += dx[0];
        be += dx[1];
        ce += dx[2];

        lastCost = cost;

        cout << "total cost: " << cost << endl;
    }
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "solve time cost = " << time_used.count() << " seconds. " << endl;
    cout << "estimated abc = " << ae << ", " << be << ", " << ce << endl;

    //将数据输入txt
    FILE *dataFile= fopen("data.txt","w");//创建文件流
    if(!dataFile){
        fprintf(stderr,"error opening data.txt");
        return 1;
    }

    for(int d=0;d<N;d++){
        fprintf(dataFile,"%f\t%f\n",x_data[d],y_data[d]);
        //将数据以浮点数\t浮点数\n的形式输入txt
    }
    fclose(dataFile);//关闭文件流

    //输出真实函数数据
    FILE *dataFile_func_R= fopen("data_r","w");
    if(!dataFile_func_R){
        fprintf(stderr,"error opening data_r.txt");
        return 1;
    }
    for(int ir=0;ir<1000;ir++){
        double xr=ir/1000;
        double yr=func_R(xr,ar,br,cr);
        fprintf(dataFile_func_R,"%f\t%f\n",xr,yr);
    }
    fclose(dataFile_func_R);

    //输出拟合函数数据
    FILE *dataFile_func_E= fopen("data_e","w");
    if(!dataFile_func_E){
        fprintf(stderr,"error opening data_e.txt");
        return 1;
    }
    for(int ie=0;ie<1000;ie++){
        double xe=ie/1000;
        double ye=func_E(xe,ae,be,ce);
        fprintf(dataFile_func_E,"%f\t%f\n",xe,ye);
    }
    fclose(dataFile_func_E);

    //输出图像
    FILE *gnuplotPipe= popen("gnuplot -persist","w");
    if(gnuplotPipe){
        fprintf(gnuplotPipe,"set terminal wxt\n");
        //fprintf(gnuplotPipe,"plot 'data.txt' with points,'data_r' with lines,'data_e' with lines\n");
        fprintf(gnuplotPipe,"plot 'data.txt' with points\n");
        fprintf(gnuplotPipe,"plot 'data_r' with lines\n,'data_e' with lines\n");
        fflush(gnuplotPipe);
        fprintf(gnuplotPipe, "exit\n");
        pclose(gnuplotPipe);
    }
    else{
        cerr<<"error with gnuplotPipe"<<endl;
    }

    return 0;
}