if HAVE_TESTS
all-local:
	mkdir -p report

if HAVE_PYTHON
check-local:
	PYTHONPATH=${abs_top_srcdir}/packaged/lib:${abs_top_builddir}/packaged/lib/:$${PYTHONPATH} \
	LD_LIBRARY_PATH=${abs_top_builddir}/packaged/lib/.libs:$${LD_LIBRARY_PATH} \
	${PYTHON} -mcoverage run ${top_srcdir}/tests/bxilog_suite.py; 

#PYTHONPATH=${abs_top_srcdir}/packaged/lib:${abs_top_builddir}/packaged/lib/:$${PYTHONPATH} \
#LD_LIBRARY_PATH=${abs_top_builddir}/packaged/lib/.libs:$${LD_LIBRARY_PATH} \
#${PYTHON} -mcoverage run ${top_srcdir}/tests/posless_suite.py
endif

TESTS = \
		unit_t\
		../packaged/doc/examples/bxistr-examples\
		../packaged/doc/examples/bxilog-err\
		../packaged/doc/examples/bxilog-cfg
if HAVE_PYTHON
TESTS += \
		${abs_top_srcdir}/packaged/doc/examples/bxilog-multiprocessing.py
endif

inst_checkdir=$(docdir)/tests/
inst_check_PROGRAMS= \
					 unit_t\
					 ../packaged/doc/examples/bxistr-examples\
					 ../packaged/doc/examples/bxilog-err\
					 ../packaged/doc/examples/bxilog-cfg

dist_inst_check_SCRIPTS=\
						bxilog_suite.py \
						posless_suite.py\
						simple_bxilog_user.py \
						simple_bxilogger.py \
						testremotehandler.py\
						remote_logger.py\
						uncaught.py\
						specific_argparse_poslessed.py\
						specific_posless.py\
						testbxierr.py\
						testparserconf.py\
						testbxilog.py

unit_t_CFLAGS =\
			   -I$(top_srcdir)/packaged/include\
			   -I$(top_srcdir)/packaged/src\
			   $(ZMQ_CFLAGS)\
			   $(UUID_CFLAGS)\
			   @TST_CFLAGS@

unit_t_LDFLAGS =\
				@TST_LDFLAGS@\
				$(ZMQ_LIBS)\
				$(UUID_LIBS)

unit_t_LDADD=$(top_builddir)/packaged/lib/libbxibase.la\
				   @TST_LIBS@


#TESTS_ENVIRONMENT=@VALGRIND@ @VALGRIND_ARGS@
AUTOMAKE_OPTIONS = parallel-tests
TEST_EXTENSIONS = .pl .sh .py
LOG_COMPILER =${VALGRIND}  `if   test "${VALGRIND}" !=  ""   ; then echo "${VALGRIND_ARGS}"; fi`
LOG_DRIVER=$(top_srcdir)/custom-test-driver
PY_LOG_DRIVER=PYTHONPATH=${abs_top_srcdir}/packaged/lib/:${abs_top_builddir}/packaged/lib/:${abs_top_srcdir}/tests:$${PYTHONPATH} \
			   PATH=${abs_top_srcdir}/packaged/bin:${abs_top_srcdir}/packaged/doc/examples:${PATH}\
			   LD_LIBRARY_PATH=${abs_top_builddir}/packaged/lib/.libs:$${LD_LIBRARY_PATH} \
			   ${LOG_DRIVER} --python ${PYTHON}

compile_tests:$(check_PROGRAMS)

unit_t$(EEXT):force

force:${top_srcdir}/valgrind.supp
	mkdir -p report
	-[ -f $$(basename $^)  ] || cp $^ .

unit_t_SOURCES=\
			   test_mem.c\
			   test_str.c\
			   test_err.c\
			   test_time.c\
			   test_zmq.c\
			   test_logger.c\
			   unit_t.c

DISTCLEANFILES=\
			   valgrind.supp\
			   ${PACKAGE_NAME}.bxilog\
			   unit_t.bxilog\
			   lt-unit_t.bxilog\
			   report/${PACKAGE_NAME}-Results.xml\
			   report/${PACKAGE_NAME}-Listing.xml

EXTRA_DIST=\
		   ../packaged/doc/examples/bxistr-examples.c\
		   ../packaged/doc/examples/bxilog-err.c\
		   ../packaged/doc/examples/bxilog-cfg.c\
		   ../packaged/doc/examples/bxilog-multiprocessing.py


___packaged_doc_examples_bxistr_examples_LDADD=$(top_builddir)/packaged/lib/libbxibase.la
___packaged_doc_examples_bxilog_err_LDADD=$(top_builddir)/packaged/lib/libbxibase.la
___packaged_doc_examples_bxilog_cfg_LDADD=$(top_builddir)/packaged/lib/libbxibase.la

___packaged_doc_examples_bxistr_examples_CFLAGS=\
										   -I$(top_srcdir)/packaged/include


___packaged_doc_examples_bxilog_err_CFLAGS=\
										   -I$(top_srcdir)/packaged/include


___packaged_doc_examples_bxilog_cfg_CFLAGS=\
										   -I$(top_srcdir)/packaged/include
endif
