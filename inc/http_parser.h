#ifndef __http_parser_h__
#define __http_parser_h__

/**
 * @file http_parser.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <unordered_map>
#include <string>
#include <algorithm>
#include <sstream>

#include "ace/Log_Msg.h"

/**
 * @brief 
 * 
 */
class Http {
  public:
    Http();
    Http(const std::string& in);
    ~Http();

    /**
     * @brief Get the uriName object
     * 
     * @return std::string 
     */
    std::string get_uriName() const {
      return(m_uriName);
    }

    /**
     * @brief Set the uriName object
     * 
     * @param uriName 
     */
    void set_uriName(std::string uriName) {
      m_uriName = uriName;
    }

    /**
     * @brief 
     * 
     * @param key 
     * @param value 
     */
    void add_element(std::string key, std::string value) {
        m_tokenMap.insert(std::pair(key, value));
    }

    /**
     * @brief Get the element object
     * 
     * @param key 
     * @return std::string 
     */
    std::string get_element(const std::string key) {
        auto it = m_tokenMap.find(key);
        if(it != m_tokenMap.end()) {
            return(it->second);
        }
        return std::string();
    }

    /**
     * @brief 
     * 
     * @return std::string 
     */
    std::string body() {
      return m_body;
    }

    /**
     * @brief 
     * 
     * @return std::string 
     */
    std::string header() {
      return m_header;
    }

    /**
     * @brief 
     * 
     * @param in 
     */
    void parse_uri(const std::string& in);
    void parse_mime_header(const std::string& in);
    void dump(void) const;
    std::string get_body(const std::string& in);
    std::string get_header(const std::string& in);

  private:
    std::unordered_map<std::string, std::string> m_tokenMap;
    std::string m_uriName;
    std::string m_header;
    std::string m_body;
};

#endif /* __http_parser_h__ */