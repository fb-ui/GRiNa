#!/bin/bash
#-----------------------------------------------------------
#	This is a tool to compile all the 
#	package that is needed in GRiNa
#	mpsk
#	2017/07/21
#-----------------------------------------------------------
LUA_ENABLED="false"
CLEAN="false"
BUILD_EXT="true"
for i in `find . -name "*.log"`; do rm $i; done
LOG_PATH="$PWD/make.log"
echo "++LOG++" > $LOG_PATH

WORK_PATH="$PWD/required"
echo $WORK_PATH

if [ $LUA_ENABLED = "true" ]; then
	echo "Lua Proccessing.."
    cd $WORK_PATH/lua
    make clean  >> $LOG_PATH
    if [$CLEAN="false"]; then 
        make -j4 all   >> $LOG_PATH
		sleep 2s
    fi
    sudo make install  >> $LOG_PATH
	echo "Lua Compiled"
fi

cd $WORK_PATH/SDL2
echo "SDL2 Proccessing.."
sh configure  >> $LOG_PATH
make clean  >> $LOG_PATH
if [ $CLEAN = "false" ]; then 
	make -j4 all  >> $LOG_PATH
	sleep 2s
	sudo make install  >> $LOG_PATH
	echo "SDL2 Compiled"
fi

echo "SDL2_image Proccessing.."
if [ $BUILD_EXT = "true" ]; then
    #   build libjpeg-dev
    cd $WORK_PATH/SDL2_image/external/jpeg-9
	sh configure  >> $LOG_PATH
	make clean  >> $LOG_PATH
	if [ $CLEAN = "false" ]; then 
		make -j4 all  >> $LOG_PATH
		sleep 2s
		sudo make install  >> $LOG_PATH
	fi
    #   build libpng-dev
    cd $WORK_PATH/SDL2_image/external/libpng-1.6.2
	sh configure  >> $LOG_PATH
	make clean  >> $LOG_PATH
	if [ $CLEAN = "false" ]; then 
		make -j4 all  >> $LOG_PATH
		sleep 2s
		sudo make install  >> $LOG_PATH
	fi
    #   build zlib
	cd $WORK_PATH/SDL2_image/external/zlib-1.2.8
	sh configure  >> $LOG_PATH
	make clean  >> $LOG_PATH
	if [ $CLEAN = "false" ]; then 
		make -j4 all  >> $LOG_PATH
		sleep 2s
		sudo make install  >> $LOG_PATH
	fi
    #   build libwebp-0.3.0
    cd $WORK_PATH/SDL2_image/external/libwebp-0.3.0
	sh configure  >> $LOG_PATH
	make clean  >> $LOG_PATH
	if [ $CLEAN = "false" ]; then 
		make -j4 all  >> $LOG_PATH
		sleep 2s
		sudo make install  >> $LOG_PATH
	fi
fi
cd $WORK_PATH/SDL2_image
sh configure  >> $LOG_PATH
make clean  >> $LOG_PATH
if [ $CLEAN = "false" ]; then 
	make -j4 all  >> $LOG_PATH
	sleep 2s
	sudo make install  >> $LOG_PATH
	echo "SDL2 Compiled"
fi

exit 0