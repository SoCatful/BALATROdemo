package game;

import java.util.ArrayList;

public class Deck {
    private ArrayList<Card> cards;
    private ArrayList<Card> savedState;

    public Deck() {
        cards = new ArrayList<>();
    }

    void initializeDeck() {
        int effect = 0;
        int value = 0;
        for (int suit = 1; suit <= 4; suit++) {
            for (int point = 1; point <= 13; point++) {
                if (point >= 2 && point <= 10) {
                    value = point;
                } else if (point >= 11) {
                    value = 10;
                } else if (point == 1) {
                    value = 11;
                }
                cards.add(new Card(point, value, suit, effect));
            }
        }
    }
    public void saveState(){
        savedState = new ArrayList<>(cards);
    }
    public void rollBack(){
        cards = new ArrayList<>(savedState);
    }
    public ArrayList<Card> getCards() {
        return cards;
    }

    void returnCards(ArrayList<Card> playedCards){
        cards.addAll(playedCards);
    }
    public int getRemainingCardsCount() {
        return cards.size();
    }
}
