//# sampleCode
/*  Design and implement a data structure for Least Recently Used (LRU) cache. 
  It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists 
  in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
  When the cache reached its capacity, it should invalidate the least recently 
  used item before inserting a new item. 
*/

class LRUCache {
  public:
    struct CacheEntry {
      int key;
      int value;
      
      CacheEntry(int k, int v):key(k), value(v) {}
    };
    
    LRUCache(int capacity) {
      m_capacity = capactiy;
    }
    
    int get(int key) {
      if (m_LRU_map.find(key) == m_LRU_map.end()) return -1;
      
      moveToHead(key);
      return m_LRU_map[key]->value;
    
    }
    
    void set(int key, int value) {
    
      if (m_LRU_map.find(key) == m_LRU_map.end()) {
        CacheEntry item(key, value);
        if (m_LRU_cache.size() >= m_capacity) {
          //remove cache from tail
          m_LRU_map.erase(m_LRU_chache.back().key);
          m_LRU_chache.pop_back();
        
        }
        
        //insert to head
        m_LRU_cache.push_front(item);
        m_LRU_map[key] = value;
        
        return;
      }
      
      //entry already existed in the cache
      m_LRU_map[key]->value = value;
      moveToHead(key);
    
    }
    
  private:
    std::unordered_map<int, std::list<CacheEntry>::iterator> m_LRU_map;
    std::list<CacheEntry> m_LRU_cache;
    int m_capacity;
    
    void moveToHead(int key) {
      // move key from current location to head
      auto updateEntry = *m_LRU_map[key];
      m_LRU_cache.erase(m_LRU_map[key]); // erase cacheEntry through iterator
      m_LRU_cache.push_front(updateEntry); // insert cacheEntry to head
      m_LRU_map[key] = m_LRU_cache.begin(); // update mapping
      
    
    }
};
