#include "Screenshot.hpp"

void ogl::Screenshot::takeScreenshot(std::string filename)
{
	GLint m_viewport[4];
	glGetIntegerv(GL_VIEWPORT, m_viewport);
	cv::Mat img(m_viewport[3], m_viewport[2], CV_8UC3);
    glPixelStorei(GL_PACK_ALIGNMENT, (img.step & 3)?1:4);
    glPixelStorei(GL_PACK_ROW_LENGTH, img.step/img.elemSize());
    glReadPixels(0, 0, img.cols, img.rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, img.data);
    cv::Mat flipped(img);
    cv::flip(img, flipped, 0);
	// cv::putText(img, text.c_str(), cv::Point(10, 35), cv::FONT_HERSHEY_PLAIN, 2.0, CV_RGB(0,0,0), 1.0);
	cv::imwrite(filename.c_str(), img);
}
