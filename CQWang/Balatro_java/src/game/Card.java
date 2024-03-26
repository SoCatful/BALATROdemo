package game;
import java.util.*;

public class Card {
    int point;
    int value;
    int suit;//spade:1 heart:2 club:3 diamond:4
    int effect;

    public Card(int point, int value, int suit, int effect) {
        this.point = point;
        this.value = value;
        this.suit = suit;
        this.effect = effect;
    }
    public String getSuitName() {
        switch (suit) {
            case 1:
                return "Spade";
            case 2:
                return "Heart";
            case 3:
                return "Club";
            case 4:
                return "Diamond";
            default:
                return "Unknown";
        }
    }
}
