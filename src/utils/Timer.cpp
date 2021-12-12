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
#include <iostream>
#include "Timer.hpp"


Timer::Timer(){}
Timer::~Timer(){}

void Timer::add(std::string const& phase,double value)
{
    auto iter = m_counters.find(phase) ;
    if(iter==m_counters.end())
    m_counters[phase] = value ;
    else
    iter->second += value ;
}

void Timer::printInfo() const {
    std::cout<<"================================"<<std::endl ;
    std::cout<<"PERF INFO : "<<std::endl ;
    for(auto const& iter : m_counters)
    {
    std::cout<<iter.first<<":"<<iter.second<<std::endl ;
    }
    std::cout<<"================================"<<std::endl ;
}


Sentry::Sentry(Timer& parent,std::string phase)
    : m_parent(parent)
    , m_phase(phase)
    {
    m_start = std::chrono::steady_clock::now();
    }

Sentry::~Sentry() {
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - m_start);

    m_parent.add(m_phase,time_span.count()) ;
    }
