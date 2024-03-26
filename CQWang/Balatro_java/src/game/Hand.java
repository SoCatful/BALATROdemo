package game;

import java.util.ArrayList;
import java.util.Random;

public class Hand {
    private ArrayList<Card> cards;
    private ArrayList<Card> playedCards;


    public Hand(Deck deck) {
        cards = new ArrayList<>();
        playedCards = new ArrayList<>();
        drawHands(deck, 8);
    }

    public void drawHands(Deck deck, int numCardsToDraw) {
        ArrayList<Card> deckCards = deck.getCards();//获取到deck里的所有牌
        Random random = new Random();
        while (cards.size() < numCardsToDraw && !deckCards.isEmpty()) {
            int randomIndex = random.nextInt(deckCards.size());
            cards.add(deckCards.remove(randomIndex));
        }
    }

    public void playCards(int[] cardIndices) {
        ArrayList<Card> cardsToRemove = new ArrayList<>();
        for (int index : cardIndices) {
            int adjustedIndex = index - 1; // 将用户输入的序号转换为数组索引
            if (adjustedIndex >= 0 && adjustedIndex < cards.size()) {
                cardsToRemove.add(cards.get(adjustedIndex));
            }
        }
        cards.removeAll(cardsToRemove);
        playedCards.addAll(cardsToRemove);
    }

    public void refillHand(Deck deck) {
        int numCardsToDraw = 8;
        drawHands(deck, numCardsToDraw);
    }

    public ArrayList<Card> getCards() {
        return cards;
    }
    public ArrayList<Card> getPlayedCards() {
        return playedCards;
    }


    public void printHand() {
        for (Card card : cards) {
            System.out.print(card.point + " " + card.getSuitName() + " | ");
        }
        System.out.println("");
    }
    //这行注释测试一下能不能正常修改文件
}
