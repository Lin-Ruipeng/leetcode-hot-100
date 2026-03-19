#!/bin/bash

echo "Start LeetCode Program!"

printf "Time: %s\n" "$(date '+%Y-%m-%d %H:%M:%S')"

numbers=$(ls -d day*_T* 2>/dev/null | sed -E 's/day([0-9]+)_T[0-9]+/\1/' | sort -n)

expected=1
for num in $numbers; do
    # 防止前导0被识别成八进制
    val=$((10#$num))

    if [ $val -gt $expected ]; then
        # 格式化输出缺失的数字，补齐到两位，比如02
        missing=$(printf "%02d" $expected)
        echo "发现中断! 缺失: day${missing}"
        echo "请自行处理缺失!"
        exit 1
        # expected=$((expected + 1)) # 永远运行不到,非必须
    fi

    expected=$((val + 1))
done

printf "Now you're going to solve your \033[43;34m%d\033[0mth algorithm problem.\n" "$expected"

read -p "The question number is : " Tnumber

read -p "The question name is   : " Qname

folder_name="day${expected}_T${Tnumber}"
file_name="${folder_name}/main.cpp"

printf "OK! Created folder and main.cpp : \n - folder: \033[43;34m%s\033[0m \n - file  : \033[43;34m%s\033[0m\n" "${folder_name}" "${file_name}"

mkdir ${folder_name}
touch ${file_name}

info_file_name="${folder_name}/.info"
start_time=$(date +%s)
echo "time:${start_time}" >$info_file_name
echo "Folder:${folder_name}" >>$info_file_name
echo "Qname:${Qname}" >>$info_file_name

cat > ${file_name} << EOF
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "Hello World!\n" << endl;
}

EOF

# g++ ./${file_name} && ./${folder_name}/a.out

echo "All is Ready! Start Coding!"

