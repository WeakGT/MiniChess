case $1 in
  1) ./build/main ./build/player_minimax ./baselines/linux/baseline1
  ;;
  2) ./build/main ./baselines/linux/baseline1 ./build/player_minimax
  ;;
  3) ./build/main ./build/player_minimax ./baselines/linux/baseline2
  ;;
  4) ./build/main ./baselines/linux/baseline2 ./build/player_minimax
  ;;
  *) echo "Error"
  ;;
esac
