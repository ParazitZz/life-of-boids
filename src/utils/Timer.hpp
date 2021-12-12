/*
 * Timer.h
 *
 *  Created on: Sep 24, 2018
 *      Author: gratienj
 */
#pragma once
#include <string>
#include <map>
#include <chrono>

class Timer
{
  public:
    Timer();
    virtual ~Timer();

    void add(std::string const& phase,double value);

    void printInfo() const;

  private :
    std::map<std::string,double> m_counters ;
};

class Sentry
{
  public :
    Sentry(Timer& parent,std::string phase);

    virtual ~Sentry();
  private:
    Timer&      m_parent ;
    std::string m_phase ;
    std::chrono::steady_clock::time_point m_start ;
};