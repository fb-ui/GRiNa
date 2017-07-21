#!/bin/bash
LUA_ENABLED="false"
CLEAN="false"
BUILD_EXT="true"

LOG_PATH="$PWD/make.log"
echo "++LOG++" > LOG_PATH

WORK_PATH="$PWD/required"
echo $WORK_PATH

if [ $LUA_ENABLED = "true" ]; then
    cd $WORK_PATH/lua

    make clean  >> $LOG_PATH
    if [$CLEAN="false"]; then 
        make -j4 all   >> $LOG_PATH
    fi
    sudo make install  >> $LOG_PATH
fi

cd $WORK_PATH/SDL2
sh configure  >> $LOG_PATH
make clean  >> $LOG_PATH
if [ $CLEAN = "false" ]; then 
	make -j4 all  >> $LOG_PATH
fi
sudo make install  >> $LOG_PATH

if [ $BUILD_EXT = "true" ]; then
    #   build libjpeg-dev
    cd $WORK_PATH/SDL2_image/external/jpeg-9
	sh configure  >> $LOG_PATH
	make clean  >> $LOG_PATH
	if [ $CLEAN = "false" ]; then 
		make -j4 all  >> $LOG_PATH
	fi
	sudo make install  >> $LOG_PATH
    #   build libpng-dev
    cd $WORK_PATH/SDL2_image/external/libpng-1.6.2
	sh configure  >> $LOG_PATH
	make clean  >> $LOG_PATH
	if [ $CLEAN = "false" ]; then 
		make -j4 all  >> $LOG_PATH
	fi
	sudo make install  >> $LOG_PATH
    #   build zlib
	cd $WORK_PATH/SDL2_image/external/zlib-1.2.8
	sh configure  >> $LOG_PATH
	make clean  >> $LOG_PATH
	if [ $CLEAN = "false" ]; then 
		make -j4 all  >> $LOG_PATH
	fi
	sudo make install  >> $LOG_PATH
    #   build libwebp-0.3.0
    cd $WORK_PATH/SDL2_image/external/libwebp-0.3.0
	sh configure  >> $LOG_PATH
	make clean  >> $LOG_PATH
	if [ $CLEAN = "false" ]; then 
		make -j4 all  >> $LOG_PATH
	fi
	sudo make install  >> $LOG_PATH
fi
cd $WORK_PATH/SDL2_image
sh configure  >> $LOG_PATH
make clean
if [ $CLEAN = "false" ]; then 
	make -j4 all  >> $LOG_PATH
fi
sudo make install  >> $LOG_PATH

exit 0