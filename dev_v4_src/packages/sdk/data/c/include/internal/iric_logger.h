#ifndef IRIC_LOGGER_H
#define IRIC_LOGGER_H

#include <string>

namespace Poco {
	class Logger;
} // Poco

namespace iRICLib {

void _iric_logger_init();

Poco::Logger& _iric_logger_get();

void _iric_logger_trace(const std::string& message);
void _iric_logger_debug(const std::string& message);
void _iric_logger_info(const std::string& message);
void _iric_logger_warn(const std::string& message);
void _iric_logger_error(const std::string& message);
void _iric_logger_error(const std::string& current, const std::string& func, int val);

void _iric_logger_trace_enter(const std::string& f_name);
void _iric_logger_trace_leave(const std::string& f_name);

void _iric_logger_trace_call_start(const std::string& f_name, const std::string& c_name);
void _iric_logger_trace_call_end(const std::string& f_name, const std::string& c_name);
void _iric_logger_trace_call_end(const std::string& f_name, const std::string& c_name, int ier);

#if _MSC_VER <= 1800
	#define __func__ __FUNCTION__
#endif // _MSC_VER

#define _IRIC_LOGGER_TRACE_ENTER() _iric_logger_trace_enter(__func__)
#define _IRIC_LOGGER_TRACE_LEAVE() _iric_logger_trace_leave(__func__)
#define _IRIC_LOGGER_TRACE_CALL_START(f_name) _iric_logger_trace_call_start(f_name, __func__)
#define _IRIC_LOGGER_TRACE_CALL_END(f_name) _iric_logger_trace_call_end(f_name, __func__)
#define _IRIC_LOGGER_TRACE_CALL_END_WITHVAL(f_name, ier) _iric_logger_trace_call_end(f_name, __func__, ier)

} // namespace iRICLib

#endif // IRIC_LOGGER_H
