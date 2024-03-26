package game;

import java.util.Scanner;

public class Game {
    public static void main(String[] args) {
        playGame();
    }

    public static void playGame() {
        Deck deck = new Deck();
        deck.initializeDeck();
        System.out.println(deck.getRemainingCardsCount());

        Hand hand = new Hand(deck);
        hand.printHand();

        Scanner scanner = new Scanner(System.in);
        boolean continueGame = true;

        while (continueGame) {
            System.out.println("请输入您想要出的牌的序号，多个序号请用空格分隔：");
            String input = scanner.nextLine();
            String[] indicesStr = input.split(" ");
            int[] indices = new int[indicesStr.length];
            for (int i = 0; i < indicesStr.length; i++) {
                indices[i] = Integer.parseInt(indicesStr[i]);
            }

            hand.playCards(indices);
            System.out.println("出牌后的手牌：");
            hand.printHand();

            System.out.println("是否继续游戏？（输入 y 继续，其他任意字符退出）");
            String choice = scanner.nextLine();
            continueGame = choice.equalsIgnoreCase("y");

            hand.refillHand(deck);
            hand.printHand();
        }
        deck.returnCards(hand.getPlayedCards());
        System.out.println(deck.getRemainingCardsCount());
    }
}


