echo "num 1" $1
echo "num 2" $2
echo "num 3" $3
if [[ $1 < $2 && $1 < $3 ]]; then echo "$1 is the smallest";
fi
if [[ $2 < $1 && $2 < $3 ]]; then echo "$2 is the smallest";
fi
if [[ $3 < $1 && $3 < $2 ]]; then echo "$3 is the smallest";
fi
