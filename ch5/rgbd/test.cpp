//测试joinMap相应代码
// Created by leonicy on 1/24/24.
//
#include <iostream>
#include <boost/format.hpp>

int main() {
    // 使用 boost::format 构建格式化字符串
//    boost::format fmt("Hello, %1% and %2%!");
    boost::format fmt("Hello,%sand%d");
    fmt % "Alice" % "Bob";

    // 将格式化字符串转换为 std::string
    std::string result = boost::str(fmt);

    // 输出结果
    std::cout << result << std::endl;

    return 0;
}
