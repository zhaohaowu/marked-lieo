数据集下载

链接: https://pan.baidu.com/s/1c9fs8DC3msUQyU3YB7OBcA  密码: 68ao

#### 首先是gazebo_chang数据集

```
cd
git clone https://github.com/zhaohaowu/marked-lieo.git
cd ~/marked-lieo
catkin_make
source devel/setup.bash
roslaunch lieo gazebo.launch
rosbag play gazebo_chang.bag
```

将在lieo的slam_data文件夹生成轨迹txt，将Ground_Truth.txt和LIEO(ours).txt移动至gazebo_chang文件夹

```
cd ~/marked-lieo
source devel/setup.bash
roslaunch lio_sam liosam_gazebo.launch
rosbag play gazebo_chang.bag
```

将在lieo的slam_data文件夹生成轨迹txt，将LIO-SAM.txt移动至gazebo_chang文件夹

```
cd ~/marked-lieo
source devel/setup.bash
roslaunch aloam aloam.launch
rosbag play gazebo_chang.bag
```

将在lieo的slam_data文件夹生成轨迹txt，将ALOAM.txt移动至gazebo_chang文件夹



#### 然后是pure_chang数据集

```
cd ~/marked-lieo
source devel/setup.bash
roslaunch lieo gazebo.launch
rosbag play pure_chang.bag
```

将在lieo的slam_data文件夹生成轨迹txt，将Ground_Truth.txt和LIEO(ours).txt移动至pure_chang文件夹

```
cd ~/marked-lieo
source devel/setup.bash
roslaunch lio_sam liosam_gazebo.launch
rosbag play pure_chang.bag
```

将在lieo的slam_data文件夹生成轨迹txt，将LIO-SAM.txt移动至pure_chang文件夹

```
cd ~/marked-lieo
source devel/setup.bash
roslaunch aloam aloam.launch
rosbag play pure_chang.bag
```

将在lieo的slam_data文件夹生成轨迹txt，将ALOAM.txt移动至pure_chang文件夹



#### 最后是sjc数据集

```
cd ~/marked-lieo
source devel/setup.bash
roslaunch lieo sjc.launch
rosbag play sjc.bag
```

将在lieo的slam_data文件夹生成轨迹txt，将Ground_Truth.txt和LIEO(ours).txt移动至sjc文件夹

```
cd ~/marked-lieo
source devel/setup.bash
roslaunch lio_sam liosam_sjc.launch
rosbag play sjc.bag
```

将在lieo的slam_data文件夹生成轨迹txt，将LIO-SAM.txt移动至sjc文件夹

```
cd ~/marked-lieo
source devel/setup.bash
roslaunch aloam aloam.launch
rosbag play sjc.bag
```

将在lieo的slam_data文件夹生成轨迹txt，将ALOAM.txt移动至sjc文件夹
