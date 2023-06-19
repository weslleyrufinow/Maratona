dir=""$(pwd)"/Inputs/"* 
for file in $dir
do
    mv $file $file.txt
done
echo "\"$(pwd)/Inputs/\""
# for file in "$(pwd)/Outputs/"*
# do
#     mv $file $file.txt
# done