# Чтобы скрипт точно успел запуститься :)
sleep 3

# Находим PID основного скрипта
mainPid=$(pgrep -f "script1")

# Находим PID его потомков
childPids=($(pgrep -P $mainPid))

echo ${childPids[*]}

# Убиваем вместе с потомками
kill $mainPid

for pid in $childPids
do
  kill $pid
done

echo "Было успешно прервано $(( ${#childPids[*]} + 1 )) процессов."
