package game;

public class HandAnalysisResult {
    private String handName; // 牌型名称
    private int baseScore;   // 基础分数

    public HandAnalysisResult(String handName, int baseScore) {
        this.handName = handName;
        this.baseScore = baseScore;
    }

    public String getHandName() {
        return handName;
    }

    public int getBaseScore() {
        return baseScore;
    }
}

