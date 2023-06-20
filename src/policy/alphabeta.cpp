#include <cstdlib>

#include "../state/state.hpp"
#include "./alphabeta.hpp"
const int inf = 1e9;

Move Alphabeta::get_move(State *state, int depth) {
  if (!state->legal_actions.size())
    state->get_legal_actions();
  Move ret;
  int max_value = -inf;
  for (const Move& ch : state->legal_actions) {
    int tmp = alphabeta(state->next_state(ch), depth - 1, -inf, inf, state->player);
    if (tmp > max_value) max_value = tmp, ret = ch;
  }
  return ret;
}

int Alphabeta::alphabeta(State* node, int depth, int alpha, int beta, bool self) {
  int ret;
  if (!depth) return node->evaluate(self);
  // if (!node->legal_actions) node->get_legal_actions();
  if (node->player == self) { // maximizing player
    ret = -inf;
    for (const Move& ch : node->legal_actions) {
      ret = std::max(ret, alphabeta(node->next_state(ch), depth - 1, alpha, beta, self));
      alpha = std::max(alpha, ret);
      if (alpha >= beta) break;
    }
  }
  else { // minimizing player
    ret = inf;
    for (const Move& ch : node->legal_actions) {
      ret = std::min(ret, alphabeta(node->next_state(ch), depth - 1, alpha, beta, self));
      beta = std::min(beta, ret);
      if (alpha >= beta) break;
    }
  }
  return ret;
}
