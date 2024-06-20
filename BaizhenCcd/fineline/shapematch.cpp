#include "shapematch.h"

shapematch::shapematch()
{


}
int shapematch::feature_show(cv::Mat& Insp, int model_id)
{
    int cw = 5;
    int cx = Insp.cols / 2;
    int cy = Insp.rows / 2;

    float angle = 0;
    float scale = 1;
    TemplateI templ = get_model_transform(model_id, angle, scale, 1);
    FeatureI* features = templ.features;
    for (int j = 0; j < templ.num_features; j++)
    {
        int r0 = cy + features[j].y;
        int c0 = cx + features[j].x;
        if (r0 >= 0 && c0 >= 0 && r0 < Insp.rows && c0 < Insp.cols)
        {
            int c = 0;
            float x = features[j].x;
            float y = features[j].y;
            Insp.at<cv::Vec3b>(r0, c0) = cv::Vec3b(0, 255, 0);
        }

    }
    clear_mems(templ.mem_id);
    return 0;
}

int shapematch::match_show(Mat& Insp, int model_id, int x0, int y0, Match* pMatches, int count, int subpixel )
{
    if (count > 0)
    {

        int p = 0;
        int cw = 5;
        for (int i = 0; i < count; i++)
        {

            float angle = pMatches[i].angle;
            float scale = pMatches[i].scale;
            float scale2 = pMatches[i].scale2;
            TemplateI templ = get_model_transform_s(model_id, angle, scale, scale2, 1);
            int tl_x = templ.tl_x;
            int tl_y = templ.tl_y;
            FeatureI* features = templ.features;
            float cy = pMatches[i].y + pMatches[i].dy;
            float cx = pMatches[i].x + pMatches[i].dx;

            for (int j = 0; j < templ.num_features; j++)
            {
                int r0 = round(cy + features[j].y + y0);
                int c0 = round(cx + features[j].x + x0);
                if (r0 >= 0 && c0 >= 0 && r0 < Insp.rows && c0 < Insp.cols)
                    Insp.at<Vec3b>(r0, c0) = Vec3b(0, 255, 0);
            }
            int r0 = round(cy + y0);
            int c0 = round(cx + x0);
            if (r0 >= 0 && c0 >= 0 && r0 < Insp.rows && c0 < Insp.cols)
            {

                line(Insp, Point(c0 - cw, r0), Point(c0 + cw, r0), Scalar(0, 0, 255), 1);
                line(Insp, Point(c0, r0 - cw), Point(c0, r0 + cw), Scalar(0, 0, 255), 1);
                //Insp.at<Vec3b>(r0, c0) = Vec3b(0, 255, 0);

                string str_score = format("%.3f", pMatches[i].score);
                cv::putText(Insp, str_score,
                    Point(pMatches[i].x + x0 + tl_x + 10, pMatches[i].y + y0 + tl_y), FONT_HERSHEY_TRIPLEX, 1, cv::Scalar(0, 0, 255));


                if (subpixel > 0){


                    // cout <<"i=" <<i+1 <<"  x=" <<cx <<"  y=" << cy<<"  角度="<<pMatches[i].angle<<"  尺度x=" <<pMatches[i].scale<<"  尺度y=" <<pMatches[i].scale2<<"  得分="<<pMatches[i].score<<endl;
                    //printf("i=%3d, x=%8.3f, y=%8.3f, 角度=%8.3f, 尺度x=%8.3f, 尺度y=%8.3f, 得分=%5.3f\n", i + 1, cx, cy, pMatches[i].angle, pMatches[i].scale, pMatches[i].scale2, pMatches[i].score);
                }
                else{
                   // cout <<"i=" <<i+1 <<"  x=" <<cx <<"  y=" << cy<<"  角度="<<pMatches[i].angle<<"  尺度x=" <<pMatches[i].scale<<"  尺度y=" <<pMatches[i].scale2<<"  得分="<<pMatches[i].score<<endl;
                   // printf("i=%3d, x=%4d, y= %4d, 角度=%8.3f, 尺度x=%8.3f, 尺度y=%8.3f, 得分=%5.3f\n", i + 1, pMatches[i].x, pMatches[i].y, pMatches[i].angle, pMatches[i].scale, pMatches[i].scale2, pMatches[i].score);
                    }

                    this->dx=cx;

                    this->dy=cy;
                    this->angle=pMatches[i].angle;


            }
            clear_mems(templ.mem_id);
        }
    }

    return 0;
}
int shapematch::test(){

         init_mwwz();

        //读取模板图像
       Mat model = imread("C:/Users/ZF/Desktop/model.bmp", IMREAD_GRAYSCALE);
         if (model.empty())
        {
            std::cout << "model empty" << endl;
            return -1;
        }
       // imshow("model", model);


       //起始角度
       double angle_start = -180;
      //终止角度
        double angle_extent = 360;

        double angle_step = 0;
        double scale_step = 0;

       // int contrast_low = 16;
       // int contrast_high = 20;
        int contrast_low = 16;
        int contrast_high = 20;
        int min_cont_len = 3;
        int min_contrast = 5;
        int contrast[4] = { contrast_low,contrast_high,min_cont_len ,min_contrast };

        int num_levels = 0;

        int use_polarity = 1;

        int model_id = -1;

         //创建模型
        int err = create_shape_model(model.ptr<uchar>(0), model.cols, model.rows, num_levels, angle_start, angle_extent, angle_step, use_polarity, contrast, NULL, model_id);

        //create model failed
        if (model_id < 0)
        {
            std::cout << "形状模型创建Fail" << endl;
            return -1;
        }

        //显示模板特征点
        Mat modelRgb;
        cvtColor(model, modelRgb, COLOR_GRAY2RGB);
        feature_show(modelRgb, model_id);
        //imshow("features", modelRgb);
         //imwrite("C:/Users/35843/Desktop/test/610/tezheng.png",modelRgb);


          //保存模板
        string modelPath = "shape_model.bin";
        int bSuccess = write_shape_model(model_id, modelPath.c_str());
        if (bSuccess == 0)
        {
            std::cout << "模型创建成功" << endl;
        }

        //读取模板图像
        Mat src = imread("C:/Users/ZF/Desktop/3.bmp", IMREAD_GRAYSCALE);
        if (src.empty())
        {
            std::cout << "模板图像为空" << endl;
            return -1;
        }
     // Mat ROI_img(src, Rect(400,400,1200,1200));


       //imshow("src", src);


        int subpixel = 1;
        double scale_min = 1;
        double scale_max = 1;
        double minScore = 0.2;
        double maxOverLap = 0.60;
        double greedness = 0.75;
        int numMatches = 1;

        if (scale_max < scale_min)
        {
            std::cout << "scale min < max" << endl;
            return -1;
        }

        int numLevels[2] = { 0 };
        int mem_id = 0;
        int nFound = 0;
        Match* pMatches = NULL;


        //模型查找
        if (abs(scale_min - 1) < DBL_EPSILON && abs(scale_max - 1) < DBL_EPSILON)
        {
            mem_id = find_shape_model(src.ptr<uchar>(0), src.cols, src.rows, model_id, angle_start, angle_extent, minScore, numMatches, maxOverLap, subpixel, numLevels, greedness, pMatches, nFound);
        }
        else
        {
            mem_id = find_scaled_shape_model(src.ptr<uchar>(0), src.cols, src.rows, model_id, angle_start, angle_extent, scale_min, scale_max, minScore, numMatches, maxOverLap, subpixel, numLevels, greedness, pMatches, nFound);
        }


        if (mem_id < 0)
        {
            std::cout << "find shape model failed" << endl;
            return -1;
        }
        else
        {
            Mat srcRgb;
            cvtColor(src, srcRgb, COLOR_GRAY2RGB);
            match_show(srcRgb, model_id, 0, 0, pMatches, nFound, subpixel);
            clear_mems(mem_id);
           // imshow("result", srcRgb);
          // imwrite("C:/Users/User/Desktop/hanguo/mid/test3.png",srcRgb);
        }
        clear_shape_model(model_id);
         return 0;

}
