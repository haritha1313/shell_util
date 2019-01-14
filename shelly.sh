 #!/bin/bash
arrayy=()
 for file in `ls /home/pegasus/Documents/image_augmentor/objects/`
    do
    arrayy+=("$file")
    done
for val in "${arrayy[@]}"
    do
   python main.py ./objects/"$val" fliph flipv rot_90,fliph
#    python main.py ./objects/"$val" zoom_150_0_300_150 zoom_0_50_300_150 zoom_200_0_300_300
    python main.py ./objects/"$val" trans_20_20 trans_0_100
    python main.py ./objects/"$val" rot_90 rot_180 rot_-90
   python main.py ./objects/"$val" noise_0.01 noise_0.02 noise_0.05
  python main.py ./objects/"$val" blur_1.0 blur_2.0 blur_4.0
    done
