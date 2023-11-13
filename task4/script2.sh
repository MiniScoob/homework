# Чтобы процессы точно успели запуститься :)
sleep 2

# Находим процессы с командой "sleep 60"
pids=( $(pgrep -f "sleep 60") )

# Убиваем 3 из них
count=0

while [ "$count" -lt "${#pids[*]}" -a "$count" -lt 3 ]
do
  kill ${pids[$count]}
  (( count++ ))
done

echo "Было успешно прервано $count процессов."
