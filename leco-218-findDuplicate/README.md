main.cpp:
609.在系统中查找重复文件。
给定一个目录信息列表，包括目录路径，以及该目录中的所有包含内容的文件，
找到文件系统中的所有重复文件组的路径。
一组重复的文件至少包括二个具有完全相同内容的文件。
输入列表中的单个目录信息字符串的格式如下：
"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
这意味着有 n 个文件
（f1.txt, f2.txt ... fn.txt 的内容分别是 f1_content, f2_content ... fn_content）
在目录 root/d1/d2/.../dm 下。注意：n>=1 且 m>=0。如果 m=0，则表示该目录是根目录。
该输出是重复文件路径组的列表。对于每个组，它包含具有相同内容的文件的所有文件路径。
文件路径是具有下列格式的字符串："directory_path/file_name.txt"

使用哈希表+isstringstream库函数。
