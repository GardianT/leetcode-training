/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue {
public:
    int front;
    int end;
    vector<int> qu;
    MyCircularQueue(int k) {
      front = 0;
      end = 0;
      qu.resize(k+1);
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        end = (end+1) % qu.size();
        qu[end] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
          return false;
        }
        front = (front + 1) % qu.size();
        return true;
    }
    
    int Front() {
      if (isEmpty()) {
        return -1;
      }
      return qu[(front+1)%qu.size()];
    }
    
    int Rear() {
      if (isEmpty()) {
        return -1;
      }
      return qu[end];
    }
    
    bool isEmpty() {
      return front == end;
    }
    
    bool isFull() {
      return (end+1) % qu.size() == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

