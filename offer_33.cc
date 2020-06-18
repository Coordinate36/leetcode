class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return _verifyPostorder(postorder, 0, postorder.size() - 1);
    }

    bool _verifyPostorder(vector<int>& postorder, int beg, int end) {
        if (beg >= end) {
            return true;
        }
        int splitIdx = beg;
        for (; splitIdx < end && postorder[splitIdx] < postorder[end]; ++splitIdx);
        for (int i = splitIdx+1; i < end; ++i) {
            if (postorder[i] < postorder[end]) {
                return false;
            }
        }
        return _verifyPostorder(postorder, beg, splitIdx - 1) && _verifyPostorder(postorder, splitIdx, end - 1);
    }
};