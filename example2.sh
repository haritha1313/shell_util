#/bin/sh
fpfunction(){
n=1
	child_pid=$!
	echo "child's pid" $child_pid

}

fork(){
    count=0
    parent_pid=$$
    echo "Parent pid is " $$
    while (($count<=1))
    do
      fpfunction &
      count=$(( count+1 ))
    done
}

fork
