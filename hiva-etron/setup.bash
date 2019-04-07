export HIVA_PATH=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
binary_path="/etron/bazel-bin/hiva"
hiva_tool_path="/etron/bazel-bin/hiva/tools"
etron_tool_path="/etron/bazel-bin/modules/tools"
recorder_path="${hiva_tool_path}/hiva_recorder"
monitor_path="${hiva_tool_path}/hiva_monitor"
visualizer_path="${etron_tool_path}/visualizer"
PYTHON_LD_PATH="/etron/bazel-bin/hiva/py_wrapper"
launch_path="${HIVA_PATH}/tools/hiva_launch"
qt_path=/usr/local/Qt5.5.1/5.5/gcc_64
rosbag_to_record_path="/etron/bazel-bin/modules/data/tools/rosbag_to_record"


export LD_LIBRARY_PATH=${qt_path}/lib:$LD_LIBRARY_PATH
export QT_QPA_PLATFORM_PLUGIN_PATH=${qt_path}/plugins
export PATH=${binary_path}:${recorder_path}:${monitor_path}:${launch_path}:${qt_path}/bin:${visualizer_path}:${rosbag_to_record_path}:$PATH
export PYTHONPATH=${PYTHON_LD_PATH}:${HIVA_PATH}/python:$PYTHONPATH

export HIVA_DOMAIN_ID=80
export HIVA_IP=127.0.0.1

export GLOG_log_dir=/etron/data/log
export GLOG_alsologtostderr=0
export GLOG_colorlogtostderr=1
export GLOG_minloglevel=0

export hiva_trans_perf=0
export hiva_sched_perf=0

# for DEBUG log
#export GLOG_minloglevel=-1
#export GLOG_v=4

source ${HIVA_PATH}/tools/hiva_tools_auto_complete.bash
