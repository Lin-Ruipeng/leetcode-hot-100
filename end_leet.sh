#!/bin/bash

# -r反向排序取最大值
day=$(ls -d day*_T* 2>/dev/null | sed -E 's/day([0-9]+)_T[0-9]+/\1/' | sort -nr | head -n 1)

# 最新的文件夹的前半名字
folder_name_re="day${day}_T*"

# 检查匹配情况
folder_list=( ${folder_name_re} )
# 获取长度
count=${#folder_list[@]}

# 检查元素个数防止意外
if [[ ${count} != 1 ]]; then
    echo "day${day}_T*的匹配结果个数不为1,请检查你创建的文件夹!"
    echo "退出!"
    exit 1
fi

# 寻找.info文件
info_path="./${folder_list}/.info"   # 文件路径
if [ ! -f ${info_path} ]; then       # 检查存在
    echo "未找到.info文件,无法自动提交! 请手动提交!"
    echo "退出!"
    exit 1
fi

# 读取文件内容
{
    read -r time_s
    read -r path_s
    read -r name_s
} < "${info_path}"

# 格式化文本
time=$(echo "${time_s}" | cut -d ":" -f 2)
path=$(echo "${path_s}" | cut -d ":" -f 2)
name=$(echo "${name_s}" | cut -d ":" -f 2)

# 1. 计算时间
end_time=$(date +%s)            # 获取当前时间
diff_time=$((end_time - time))  # 时间戳的差
hours=$((diff_time / 3600))
min_s=$(( (diff_time % 3600) / 60 )) 
sec_s=$((diff_time % 60))
echo "对于 ${name} 这道题,你的总用时为:"
echo " ${hours} 小时 ${min_s} 分 ${sec_s} 秒"

# 2. 拼接提交信息
git_msg="${path}_${name}"

# git提交内容
git add ${folder_list}
git commit -m "${git_msg}"

# 最后还需要删除这个临时的文件
rm ${info_path}

echo "已经帮你把代码自动提交到本地仓库了"
echo "提交信息为: ${git_msg}"
echo "最后,别忘了 push 一下,我的老伙计!"

