 #!/bin/bash
arrayy=()
 for file in `ls /home/pegasus/Documents/image_augmentor/objects`
    do
    echo "$file"
    arrayy+=("$file")
    done
for val in "${arrayy[@]}"
    do
    cd /home/pegasus/Documents/image_augmentor/objects/"$val" 
   mogrify -resize 400X400 *.jpg
   mogrify -resize 400X400 *.JPG
    cd ..
done
