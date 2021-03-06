// Copyright © 2018-2019 Tokarev Artem Alekseevich. All rights reserved.
// Licensed under the MIT License.

#include "logger.h"


void Logger::flush() {
    if (m_turnFlag != 0) {
        if (m_turnFlag == 1)
            m_values.push_back("");
        m_endings.push_back("");
    }

    std::size_t max_descriptions_size = 0;
    for (std::size_t i = 0; i < m_descriptions.size(); i++)
        if (m_descriptions[i].size() > max_descriptions_size)
            max_descriptions_size = m_descriptions[i].size();

    std::size_t extended_line_description_size = max_descriptions_size + 6;

    for (std::size_t i = 0; i < m_descriptions.size(); i++) {
        *m_stream << ">>  " + m_descriptions[i] + std::string(extended_line_description_size - m_descriptions[i].size(), '.')
            + ">>  " + m_values[i] + ' ' + m_endings[i] + '\n';
    }
}


Logger::Iomanip<Logger::IomanipType::Width> Logger::setw(std::streamsize new_width) {
    return Iomanip<IomanipType::Width>{ new_width };
}

Logger::Iomanip<Logger::IomanipType::Precision> Logger::setprecision(std::streamsize new_precision) {
    return Iomanip<IomanipType::Precision>{ new_precision };
}


void Logger::open(std::ostream& stream) {
    m_stream = &stream;
}


void Logger::clear() {
    m_descriptions.clear();
    m_values.clear();
    m_endings.clear();
}


std::streamsize Logger::width() const {
    return m_bufiss->width();
}


std::streamsize Logger::width(std::streamsize new_width) {
    return m_bufiss->width(new_width);
}


std::streamsize Logger::precision() const {
    return m_bufiss->precision();
}


std::streamsize Logger::precision(std::streamsize new_precision) {
    return m_bufiss->precision(new_precision);
}


std::ios::fmtflags Logger::setf(std::ios::fmtflags flags) {
    return m_bufiss->setf(flags);
}


std::ios::fmtflags Logger::setf(std::ios::fmtflags flags, std::ios::fmtflags mask) {
    return m_bufiss->setf(flags, mask);
}


void Logger::istreamTypeOperatorHelper() {
    m_values.push_back(m_bufiss->str());
    std::ios::fmtflags fmtflags_buf = m_bufiss->flags();
    m_bufiss.reset(new std::stringstream(std::ios::in | std::ios::out));
    m_bufiss->flags(fmtflags_buf);
}


Logger& Logger::operator<<(short value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(unsigned short value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(int value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(unsigned int value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(long value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(unsigned long value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(long long value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(unsigned long long value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(float value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(double value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(long double value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(bool value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(const void* value) {
    if (m_turnFlag != 1)
        throw std::logic_error("Wrong input order.\nError in function: Logger::operator<<");

    *m_bufiss << value;
    istreamTypeOperatorHelper();

    m_turnFlag++;
    return *this;
}


Logger& Logger::operator<<(const char* value) {
    return *this << std::string(value);
}


Logger& Logger::operator<<(const std::string& str) {
    switch (m_turnFlag) {
    case 0:
        m_descriptions.push_back(str);
        m_turnFlag++;
        break;
    case 1:
        m_values.push_back(str);
        m_turnFlag++;
        break;
    case 2:
        m_endings.push_back(str);
        m_turnFlag = 0;
        break;
    }

    return *this;
}


Logger& Logger::operator<<(std::ios_base& (*func)(std::ios_base&)) {
    *m_bufiss << func;
    return *this;
}


Logger& Logger::operator<<(std::ostream& (*func)(std::ostream&)) {
    if (func != static_cast<std::ostream & (*)(std::ostream&)>(std::endl))
        * m_bufiss << func;
    return *this;
}


template <Logger::IomanipType IomT>
Logger& Logger::operator<<(Logger::Iomanip<IomT> ioManip) {
    switch (IomT) {
    case IomanipType::Width:     m_bufiss->width(ioManip.param); break;
    case IomanipType::Precision: m_bufiss->precision(ioManip.param); break;
    }

    return *this;
}




Logger::Logger() {
    m_bufiss.reset(new std::stringstream(std::ios::in | std::ios::out));
}


Logger::Logger(std::ostream& stream) {
    m_bufiss.reset(new std::stringstream(std::ios::in | std::ios::out));
    open(stream);
}


Logger::~Logger() {
    if (m_stream) flush();
}
