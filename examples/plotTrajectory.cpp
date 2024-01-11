#include <pangolin/pangolin.h>
#include <eigen3/Eigen/Core>
#include <unistd.h>//～

// 本例演示了如何画出一个预先存储的轨迹

using namespace std;
using namespace Eigen;

// path to trajectory file
string trajectory_file = "/home/leonicy/SLAM2.0/slambook2/ch3/examples/trajectory.txt";

void DrawTrajectory(vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>>);
//定义一个画轨迹的函数,函数变量为vector,vector中元素类型为Isometry3d/ ～

int main(int argc, char **argv) {

  vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>> poses;//一个向量，向量的元素形式是Isometry3d
  ifstream fin(trajectory_file);//建立名为fin的对象，并开始文件输入流
  if (!fin) {
    cout << "cannot find trajectory file at " << trajectory_file << endl;
    return 1;
  }//如果fin地址对应的文件没有正常打开，输出语句并返回1

  while (!fin.eof()) {//fin.eof，如果没有到file结尾返回true
    double time, tx, ty, tz, qx, qy, qz, qw;
    fin >> time >> tx >> ty >> tz >> qx >> qy >> qz >> qw;//输入流
    Isometry3d Twr(Quaterniond(qw, qx, qy, qz));//在Ter中通过四元数存储旋转矩阵
    Twr.pretranslate(Vector3d(tx, ty, tz));//进行平移
    poses.push_back(Twr);//将其Twr对应的齐次变换矩阵存储在poses元素中
  }
  cout << "read total " << poses.size() << " pose entries" << endl;//返回poses记录的元素（向量）数量

  // draw trajectory in pangolin
  DrawTrajectory(poses);//绘制轨迹
  return 0;
}

/*******************************************************************************************/
void DrawTrajectory(vector<Isometry3d, Eigen::aligned_allocator<Isometry3d>> poses) {
  // create pangolin window and plot the trajectory
  //pangolin初始化设置
  pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);//创建窗口
  glEnable(GL_DEPTH_TEST);//开启深度模式
  glEnable(GL_BLEND);//开启混合模式，实现半透明
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//blend模式
//****
  pangolin::OpenGlRenderState s_cam(//定义了一个pangolin渲染对象
    pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
    pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0)
  );

  pangolin::View &d_cam = pangolin::CreateDisplay()
    .SetBounds(0.0, 1.0, 0.0, 1.0, -1024.0f / 768.0f)
    .SetHandler(new pangolin::Handler3D(s_cam));

  while (pangolin::ShouldQuit() == false) {//点击窗口的推出，ShouldQuit即变为
      //设置输出参数
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    d_cam.Activate(s_cam);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glLineWidth(2);
    for (size_t i = 0; i < poses.size(); i++) {
      // 画每个位姿的三个坐标轴
      Vector3d Ow = poses[i].translation();
      Vector3d Xw = poses[i] * (0.1 * Vector3d(1, 0, 0));
      Vector3d Yw = poses[i] * (0.1 * Vector3d(0, 1, 0));
      Vector3d Zw = poses[i] * (0.1 * Vector3d(0, 0, 1));
      glBegin(GL_LINES);
      glColor3f(1.0, 0.0, 0.0);
      glVertex3d(Ow[0], Ow[1], Ow[2]);
      glVertex3d(Xw[0], Xw[1], Xw[2]);
      glColor3f(0.0, 1.0, 0.0);
      glVertex3d(Ow[0], Ow[1], Ow[2]);
      glVertex3d(Yw[0], Yw[1], Yw[2]);
      glColor3f(0.0, 0.0, 1.0);
      glVertex3d(Ow[0], Ow[1], Ow[2]);
      glVertex3d(Zw[0], Zw[1], Zw[2]);
      glEnd();
    }
    // 画出连线
    for (size_t i = 0; i < poses.size(); i++) {
      glColor3f(0.0, 0.0, 0.0);
      glBegin(GL_LINES);
      auto p1 = poses[i], p2 = poses[i + 1];
      glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
      glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
      glEnd();
    }
    pangolin::FinishFrame();
    usleep(5000);   // sleep 5 ms
  }
}
