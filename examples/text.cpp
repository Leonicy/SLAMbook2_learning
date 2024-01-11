//
// Created by leonicy on 12/16/23.

#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;
int main()
{
    Isometry3d M_e=Isometry3d ::Identity();
    M_e.translation()<<1.0,1.0,1.0;
    Matrix3d R_M;
    M_e.rotation()= R_M;
    R_M<<0.0,-1.0,0.0,
        -1.0,0.0,0.0,
        0.0,0.0,1.0;

    cout<<"M_e after translating and rotating by rename matrix is"<<M_e<<endl;

    M_e.rotate(AngleAxisd(-M_PI/4,Vector3d::UnitZ()));
    M_e.pretranslate(Vector3d(-1,-1,-1));
    cout<<"M_e after translating and rotating by verb is"<<M_e<<endl;

    return 0;
}

//###测试Pangolin###///
//#include <pangolin/pangolin.h>
//
//int main() {
//    // 创建Pangolin窗口
//    pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);
//
//    // 启用OpenGL功能
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//    // 定义渲染状态对象s_cam
//    pangolin::OpenGlRenderState s_cam(
//            pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
//            pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0)
//    );
//
//    // 创建一个相机视图
//    pangolin::Handler3D handler(s_cam);
//
//    // 创建一个交互视图
//    pangolin::View& d_cam = pangolin::CreateDisplay()
//            .SetBounds(0.0, 1.0, 0.0, 1.0, -1024.0f/768.0f)
//            .SetHandler(&handler);
//
//    while (!pangolin::ShouldQuit()) {
//        // 清空缓冲区
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        // 在这里添加渲染场景的代码...
//
//        // 交换缓冲区并检查事件
//        pangolin::FinishFrame();
//    }
//
//    return 0;
//}


//###测试Isometry###//

//#include <iostream>
//#include <Eigen/Dense>

//int main() //Isometry
//{
//    Eigen::Isometry3d transform = Eigen::Isometry3d::Identity();
//
//    // 平移
//    transform.translation() << 1.0, 2.0, 3.0;
//
//    // 旋转（示例：绕 Z 轴旋转 45 度）
//    transform.rotate(Eigen::AngleAxisd(M_PI/4, Eigen::Vector3d::UnitZ()));
//
//    // 将变换应用于矢量
//    std::cout<<transform.matrix()<<std::endl;
//
//    Eigen::Vector3d originalVector(1.0, 0.0, 0.0);
//    Eigen::Vector3d transformedVector = transform * originalVector;
//
//    std::cout << "原始矢量：" << originalVector.transpose() << std::endl;
//    std::cout << "变换后的矢量：" << transformedVector.transpose() << std::endl;
//
//    return 0;
//}

