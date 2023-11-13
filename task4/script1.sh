finishedTaskCount=0
child_pids=()

for i in {1..5}
do
  sleep 20 &
  
  child_pid=$!
  child_pids+=($child_pid)
done

# Ждем завершения всех дочерних процессов
for pid in ${child_pids[*]}
do
  wait $pid
  exitCode=$?
  if [ "$exitCode" -eq 0 ]
    then (( finishedTaskCount++ ))
  fi
done

echo "Завершено процессов: $finishedTaskCount." > output.txt

sleep 3600
