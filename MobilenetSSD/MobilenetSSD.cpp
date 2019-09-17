// MobilenetSSD.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
	dnn::Net _net;
	switch (argc)
	{
	case 4:
		Mat image = imread(argv[1]);
		_net = cv::dnn::readNetFromCaffe(argv[2], argv[3]);
		_net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
		_net.setPreferableTarget(cv::dnn::DNN_TARGET_OPENCL);

		//cv::Mat image(height, width, CV_8UC4, data);
		cv::Mat blob;
		//cv::cvtColor(bgra, rgb, cv::COLOR_BGRA2BGR);
		blob = cv::dnn::blobFromImage(image, 1.0, cv::Size(), cv::Scalar(), false, false);
		_net.setInput(blob);
		cv::Mat probs = _net.forward();
		// この後　http://tecsingularity.com/opencv/opencv_googlenet/

		imshow("Image", image);
		while (true)
		{
			int c = waitKey(10);
			if (c == 'q' || c == 'Q')
				break;
		}
	}
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
