/*
 * File: linkedhashmap.h
 * ---------------------
 * This file exports the <code>LinkedHashMap</code> class, which stores
 * a set of <i>key</i>-<i>value</i> pairs.
 * Identical to a HashMap except that upon iteration using a for-each loop
 * or << / toString call, it will emit its key/value pairs in the order they
 * were originally inserted.  This is provided at a runtime and memory
 * cost due to needing to store an extra copy of the keys.
 * 
 * @author Marty Stepp
 * @version 2016/09/24
 * - refactored to use collections.h utility functions
 * @version 2016/09/22
 * - added support for std initializer_list usage, such as
 *   {{"a", 1}, {"b", 2}, {"c", 3}} in constructor, putAll, removeAll, retainAll,
 *   operators +, +=, -, -=, *, *=
 * - added addAll method
 * - added operators <, <=, >, >=
 * @version 2016/08/12
 * - bug fix in operator >>
 * @version 2016/08/04
 * - fixed operator >> to not throw errors
 * @version 2015/10/26
 * - initial version
 * @since 2015/10/26
 */

#ifndef _linkedhashmap_h
#define _linkedhashmap_h
#include <unordered_map>
#include <list>
#include <utility>
#include <vector>

template <class K, class V>
class LinkedHashMap {
private:
	typedef typename std::vector<K>::iterator list_iterator;
	std::unordered_map< K, std::pair<V, list_iterator > > hash; 
	std::vector<K> ls;
public:
	const unsigned long size() noexcept { return hash.size(); }
	const bool empty() noexcept { return hash.empty(); }
	
	void insert(std::pair<K,V>&& kv) {
		auto const p = hash.find(kv.first);
		if (p != hash.end()) {
			p->second.first = std::move(kv.second);
		} else {
			auto const it = ls.insert(ls.end(), kv.first);
			try {
				hash.insert( std::make_pair(std::move(kv.first), std::make_pair(std::move(kv.second), it)));
			}
			catch (...) {
				ls.erase(it);
				throw;
			}
		}
	}
	void insert(std::pair<K,V> const& kv) {
		auto const p = hash.find(kv.first);
		if (p != hash.end()) {
			p->second.first = std::move(kv.second);
		} else {
			ls.push_back(kv.first);
			try {
				auto it = ls.end(); --it;
				hash.insert( std::make_pair(kv.first, std::make_pair(kv.second, it)));
			}
			catch (...) {
				ls.pop_back();
				throw;
			}
		}
	}
	void erase(K const& key) {
		auto const p = hash.find(key);
		if (p != hash.end()) {
			ls.erase(p->second.second);
			hash.erase(p);
		}
	}
	void eraseEldest() {
		if(!hash.empty()) {
			hash.erase(ls.front());
			ls.pop_front();
		}
	}
	void eraseNewest() {
		if(!hash.empty()) {
			hash.erase(ls.back());
			ls.pop_back();
		}
	}
	V& at(K const& key) {
		return hash.at(key).first;
	}
	V const& at(K const& key) const {
		return hash.at(key).first;
	}
	V& operator[](K const& key) {
		return hash[key].first;
	}
	V const& operator[](K const& key) const {
		return hash[key].first;
	}
	std::vector<K const> keyList() {
		return ls;
	}

    class iterator : public std::vector<K>::iterator {
    public:
        iterator() : std::vector<K>::iterator() {}
        iterator(const iterator& it) : std::vector<K>::iterator(it) {}
        iterator(const typename std::vector<K>::iterator& it) :std::vector<K>::iterator(it) {}
    };

    /*
     * Returns an iterator positioned at the first key of the map.
     */
    iterator begin()  {
        return iterator(ls.begin());
    }

    /*
     * Returns an iterator positioned at the last key of the map.
     */
    iterator end()  {
        return iterator(ls.end());
    }
};

#endif // _linkedhashmap_h
