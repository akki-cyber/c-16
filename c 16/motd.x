/* This describes the set of remote procedures our
   program supports. The program number for this
   interface is at the end. */
program MOTD_PROG {
        /* This gives the types of procedures for a
           version of our program (version 1) */
        version MOTD_VERS {
                /* Return the current number of messages. */
                int COUNT( void ) = 1;

                /* Get the message at the given index. */
                string GET( int ) = 2;
        } = 1;
} = 0x5F000001;
