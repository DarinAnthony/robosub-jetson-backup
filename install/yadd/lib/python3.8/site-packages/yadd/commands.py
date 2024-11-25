setup_commands = [
    # Restore factory default settings in the ExplorerDVL
    'CR1',
    # Flow Control – set to default
    'CF11110',
    # Enable single-ping bottom track
    'BP001',
    # Set maximum bottom search depth to 100 meters
    'BX01000',
    # Set Heading Alignment to 0 degrees
    'EA00000',
    # Set Salinity to saltwater
    'ED0000',
    # Set Salinity to saltwater
    'ES35',
    # Output earth coordinates, use tilts, allow 3 beam solutions and bin mapping
    # 'EX11111',
    # Ship coordinates (Note 1) X, Y, Z vectors relative to the ship. Heading 
    # not applied. EA-command used, but not the #EV- command. If Bit 3 of the 
    # EX-command is a 1, then Pitch/Roll applied.
    'EX10111',
    # Set to use external sensors
    'EZ22222220',
    # Set Time between Ensembles to zero (ExplorerDVL will ping as fast as possible)
    'TE00000000',
    # Set Time between Pings to zero (ExplorerDVL will ping as fast as possible)
    'TP00:00.00',
    # To use water profiling, set the WP command >0
    'WP0',
    # Bin size set to 200 cm
    'WS0200',
    # Number of bins set to 30
    'WN030',
    # Disable Water-Mass Layer Mode (default)
    '#BK0',
    # Bottom track high resolution BJ tc* hrn ***, * have to be 0, and h is 1
    # for high resolution
    '#BJ 000 100 000',
    # Set Water-Mass Layer parameters to minimum 20 meters, near 80 meters, far
    # 160 meters (600kHz default)
    '#BL20,80,160',
    # Turnkey mode on (default) - ExplorerDVL will ping when power turned on.
    '#CT1',
    # Environmental Data Output – sets specialized attitude data types Piston transducer default, for Phased Array transducer use #EE0000111
    '#EE0000101',
    # Set Heading Bias to 0 degrees NOTE. Set #EV = [(local magnetic declaration)*100] + (-4500) to compensate for the transducer misalignment (if used).
    '#EV00000',
    # Select type of external sensor to use
    '#EY 0 0 0 0 0 0 0 0',
    # Set output data format to #PD0
    '#PD0',
    # Save this setup to non-volatile memory in the ExplorerDVL
    'CK',
]
