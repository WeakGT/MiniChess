#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"
const int inf = 1e9;

Move Minimax::get_move(State *state, int depth) {
  if (!state->legal_actions.size())
    state->get_legal_actions();
  Move ret;
  int max_value = -inf;
  for (const Move& ch : state->legal_actions) {
    int tmp = minimax(state->next_state(ch), depth - 1, state->player);
    if (tmp > max_value) max_value = tmp, ret = ch;
  }
  return ret;
}

int Minimax::minimax(State* node, int depth, bool self) {
  int ret;
  if (!depth) return node->evaluate(self);
  // if (!node->legal_actions) node->get_legal_actions();
  if (node->player == self) { // maximizing player
    ret = -inf;
    for (const Move& ch : node->legal_actions)
      ret = std::max(ret, minimax(node->next_state(ch), depth - 1, self));
  }
  else { // minimizing player
    ret = inf;
    for (const Move& ch : node->legal_actions)
      ret = std::min(ret, minimax(node->next_state(ch), depth - 1, self));
  }
  return ret;
}
