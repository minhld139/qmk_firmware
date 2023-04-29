SRC += siegfried.c

ifdef ENCODER_ENABLE
	# include encoder related code when enabled
	ifeq ($(strip $(ENCODER_DEFAULTACTIONS_ENABLE)), yes)
		OPT_DEFS += -DENCODER_DEFAULTACTIONS_ENABLE
	endif
	SRC += siegfried_encoder.c
endif

ifeq ($(strip $(IDLE_TIMEOUT_ENABLE)), yes)
    OPT_DEFS += -DIDLE_TIMEOUT_ENABLE
endif
