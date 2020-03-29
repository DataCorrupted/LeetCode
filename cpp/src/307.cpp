class SegNode {
  int val;
  SegNode *leftChild;
  SegNode *rightChild;
  int left, right;

 public:
  SegNode(vector<int> &nums, int i, int j) : left(i), right(j) {
    if (i == j) {
      val = nums[i];
      leftChild = nullptr;
      rightChild = nullptr;
      return;
    } else {
      int mid = (i + j) / 2;
      leftChild = new SegNode(nums, i, mid);
      rightChild = new SegNode(nums, mid + 1, j);
      val = leftChild->getVal() + rightChild->getVal();
    }
  }
  ~SegNode() {
    if (leftChild) {
      delete leftChild;
    }
    if (rightChild) {
      delete rightChild;
    }
  }

  int getVal() const { return val; }
  int getLeft() const { return left; }
  int getRight() const { return right; }

  void update(int i, int v) {
    if (i == left && i == right) {
      val = v;
    } else {
      if (i <= leftChild->getRight()) {
        leftChild->update(i, v);
      } else if (i >= rightChild->getLeft()) {
        rightChild->update(i, v);
      }
      val = leftChild->getVal() + rightChild->getVal();
    }
  }
  int sumRange(int i, int j) {
    if (i == -1) {
      i = left;
    }
    if (j == -1) {
      j = right;
    }

    if (i < left || j > right) {
      cout << " I got a query larger than me, that's weird.\n";
      return -1;
    }

    if (i == left && j == right) {
      return val;
    }
    if (i > leftChild->getRight()) {
      return rightChild->sumRange(i, j);
    }
    if (j < rightChild->getLeft()) {
      return leftChild->sumRange(i, j);
    }
    // Use -1 to denote start/end point.
    return leftChild->sumRange(i, -1) + rightChild->sumRange(-1, j);
  }
};

class NumArray {
  SegNode *segTree = nullptr;

 public:
  NumArray(vector<int> nums) {
    if (nums.size() == 0) {
      return;
    }
    segTree = new SegNode(nums, 0, nums.size() - 1);
  }
  ~NumArray() {
    if (segTree) {
      delete segTree;
    }
  }

  void update(int i, int val) {
    if (segTree) {
      segTree->update(i, val);
    }
  }

  int sumRange(int i, int j) {
    if (segTree) {
      return segTree->sumRange(i, j);
    } else {
      return 0;
    }
  }
};

#ifdef DEBUG
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
static NumArray example1({1, 3, 5});

REGISTER_TEST(example1) {
  vector<int> result;

  result.push_back(example1.sumRange(0, 2));
  example1.update(1, 2);
  result.push_back(example1.sumRange(0, 2));
  example1.update(0, 12);
  result.push_back(example1.sumRange(1, 2));
  result.push_back(example1.sumRange(0, 2));
  vector<int> groundTruth({9, 8, 7, 19});
  return result == groundTruth;
}

static NumArray example2({});

REGISTER_TEST(example2) {
  vector<int> result;

  result.push_back(example2.sumRange(0, 2));
  example2.update(0, 12);
  result.push_back(example2.sumRange(0, 2));
  vector<int> groundTruth({0, 0});
  return result == groundTruth;
}

#endif