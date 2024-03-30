package game;

import java.util.*;

public class HandAnalyzer {
    public static HandAnalysisResult analyzeHand(ArrayList<Card> hand) {
        // 实现牌型分析的逻辑，并根据分析结果创建一个 HandAnalysisResult 对象返回
        String handName = ""; // 计算得到的牌型名称
        int baseScore = 0;    // 计算得到的基础分数
        return new HandAnalysisResult(handName, baseScore);
    }
}
