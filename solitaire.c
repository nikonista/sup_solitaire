#include <stdio.h>

enum COLORS { SRCE, BAKLAVA, PIK, LIST, ENUM_COUNT };
enum VALUES { VALUE_A, VALUE_2, VALUE_3, VALUE_4, VALUE_5, VALUE_6, VALUE_7, VALUE_8, VALUE_9, VALUE_10, VALUE_J, VALUE_Q, VALUE_K, ENUM_COUNT };

typedef struct {
    enum COLORS color;
    enum VALUES value;
} Card;

int is_black(Card card) {
    return card.color == PIK || card.color == LIST;
}

int is_red(Card card) {
    return card.color == SRCE || card.color == BAKLAVA;
}

int is_alternate_color(Card lower, Card upper) {
    return (is_red(lower) && is_black(upper)) || (is_black(lower) && is_red(upper));
}

int is_in_sequence(Card lower, Card upper) {
    return (lower.value + 1) == upper.value;
}

int can_be_placed_bottom(Card lower, Card upper) {
    return is_alternate_color(lower, upper) && is_in_sequence(lower, upper);
}

int is_same_color(Card lower, Card upper) {
    return lower.color == upper.color;
}

int can_be_placed_foundation(Card lower, Card upper) {
    return is_same_color(lower, upper) && is_in_sequence(lower, upper);
}

typedef struct card_node {
    Card card;
    struct card_node *next;
} card_node;

typedef struct deck{
    card_node *head;
    int num_cards;
}deck;


typedef struct game_state {
    deck **decks;
    int deck_count;
} game_state;

int main() {
    printf("Hello, World!\n");
    return 0;
}