for i in {1..5}; do
name="test0$i"
mkdir $name
cd $name
mkdir 01
cd 01
touch test.txt
date > test.txt
cd ..
mkdir 02
cd 02
touch test.txt
date > test.txt
cd ..
cd ..
done 
for i in {1..5};do
cat "test0$i/01/test.txt" "test0$i/02/test.txt" >> txtfile.txt
done
