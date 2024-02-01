//测试读取图像某一通道像素值
// Created by leonicy on 1/22/24.
//
#include <iostream>
//#include <chrono>

using namespace std;

#include <opencv2/core/core.hpp>//core核心库
#include <opencv2/highgui/highgui.hpp>//

int main(int argc, char **argv)
{
    cv::Mat image;
    image=cv::imread(argv[1]);
    //读取函数运行后跟的第一个参数
    //判断是否成功读取
    if(image.data==nullptr){
        cerr<<"图片"<<argv[1]<<"不存在"<<endl;
        return 0;
    }
    cout<<"图像宽为"<<image.cols<<"图像高为"<<image.rows<<"图像通道数为"<<image.channels()<<endl;
    cv::imshow("image",image);
    cv::waitKey(0);
    //判断图像类别
    if (image.type()!=CV_8UC1 && image.type()!=CV_8UC3){
        cout<<"图像类别错误，不为灰度图或彩色图"<<endl;
        return 0;
    }
    size_t x_mid= round(image.cols/2);
    size_t y_mid= round(image.rows/2);//round取正
    unsigned char *row_ptr=image.ptr<unsigned char> (y_mid);
    unsigned char *data_ptr=&row_ptr[x_mid*image.channels()];
    for(int c=0;c<image.channels();c++){
        unsigned char data=data_ptr[c];
        cout<<"图像中间区域"<<"["<<x_mid<<","<<y_mid<<"]处的第"<<c+1<<"通道像素值为"<<static_cast<int>(data)<<endl;
        //需要将unsigned char格式的data转为int
    }
    return 0;
}



