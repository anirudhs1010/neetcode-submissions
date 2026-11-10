class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        #len(hands)/groupsize represents the number of mins we have
        if len(hand) % groupSize != 0: return False
        cnt = Counter(hand)

        for c in sorted(cnt.keys()):

            frq = cnt[c]
            if frq > 0:
                for i in range(groupSize):
                    if cnt[c+i] < frq:
                        return False
                    cnt[c+i] -= frq
        return True


