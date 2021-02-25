if(OPENCVOPTION MATCHES "ON")
SET(OPENCV_LIB
-lopencv_core
-lopencv_highgui
-lopencv_imgproc
-lopencv_imgcodecs)
elseif(OPENCVOPTION MATCHES "OFF")
SET(OPENCV_LIB "")
endif()
