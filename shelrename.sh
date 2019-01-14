#!/bin/bash
 for file in `ls /home/pegasus/Documents/image_augmentor/objects`
    do
    echo "$file"
    arrayy+=("$file")
    done
p=0
for val in "${arrayy[@]}"
    do
    cd /home/pegasus/Documents/image_augmentor/objects/"$val" 
#   rename 's/\.JPG$/.jpg/' *.JPG 
    for i in *.jpg;
do
  mv "$i" "d$p.jpg"
  ((p++))
done
    cd ..
done
