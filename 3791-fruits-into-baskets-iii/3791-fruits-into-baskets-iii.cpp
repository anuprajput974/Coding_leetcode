class SegmentTree {
public:
    vector<int> tree;
    int n;

    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 0, 0, n - 1);
    }

    void build(const vector<int>& data, int node, int l, int r) {
        if (l == r) {
            tree[node] = data[l];
            return;
        }
        int mid = (l + r) / 2;
        build(data, 2 * node + 1, l, mid);
        build(data, 2 * node + 2, mid + 1, r);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int query(int val, int node, int l, int r) {
        if (tree[node] < val) return -1;
        if (l == r) return l;
        int mid = (l + r) / 2;
        int left = query(val, 2 * node + 1, l, mid);
        if (left != -1) return left;
        return query(val, 2 * node + 2, mid + 1, r);
    }

    void update(int index, int val, int node, int l, int r) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (index <= mid) update(index, val, 2 * node + 1, l, mid);
        else update(index, val, 2 * node + 2, mid + 1, r);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        SegmentTree seg(baskets);
        int unplaced = 0;

        for (int fruit : fruits) {
            int idx = seg.query(fruit, 0, 0, n - 1);
            if (idx == -1) {
                unplaced++;
            } else {
                seg.update(idx, 0, 0, 0, n - 1);
            }
        }

        return unplaced;
    }
};
