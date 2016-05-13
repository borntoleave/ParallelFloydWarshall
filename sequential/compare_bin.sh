#! /bin/bash
if [ $# -ne 2 ]; then
	echo "Format: $0 bin_file_1 bin_file_2"
	exit;
fi 

./check $1 0 >temp1
./check $2 0 >temp2
echo "Compare two binary files...."
diff temp1 temp2
echo "Finished comparing."
rm temp*
