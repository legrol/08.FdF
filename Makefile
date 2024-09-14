# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME 				= fdf

# ══ Colors ══════════════════════════════════════════════════════════════════ #
#    ------                                                                    #

DEL_LINE 			= \033[2K
ITALIC 				= \033[3m
BOLD 				= \033[1m
DEF_COLOR 			= \033[0;39m
GRAY 				= \033[0;90m
RED 				= \033[0;91m
GREEN 				= \033[0;92m
YELLOW 				= \033[0;93m
BLUE 				= \033[0;94m
MAGENTA 			= \033[0;95m
CYAN 				= \033[0;96m
WHITE 				= \033[0;97m
BLACK 				= \033[0;99m
ORANGE 				= \033[38;5;209m
BROWN 				= \033[38;2;184;143;29m
DARK_GRAY 			= \033[38;5;234m
MID_GRAY 			= \033[38;5;245m
DARK_GREEN 			= \033[38;2;75;179;82m
DARK_YELLOW 		= \033[38;5;143m

# ══ Compilation══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

CC 					= clang
AR 					= ar rcs
RM 					= rm -f
MK 					= make -C -g
MKD					= mkdir -p
MCL 				= make clean -C
MFCL 				= make fclean -C
MK_					= && make

# ══ Directories ═════════════════════════════════════════════════════════════ #
#    -----------                                                               #

SRC_DIR				= ./src
CONTROL_DIR			= ./control
DRAW_DIR			= ./draw
ERRORS_DIR			= ./errors
FREE_DIR			= ./free
INIT_DIR			= ./init
UTILS_DIR			= ./utils
LIBRARIES			= ./libs
OBJ_DIR				= ./obj
PERIPHERALS_DIR		= ./peripherals
LIBFT_DIR			= libft
PRINTFT_DIR			= printf
EXAMFT_DIR			= examft
GNL_DIR				= gnl
INCLUDES_DIR		= ./includes
MLX42_LIB			= ./MLX42/lib
MLX42_INCLUDE		= ./MLX42/include/MLX42

# ══ Bonus Directories ═══════════════════════════════════════════════════════ #
#    -----------------                                                         #

# SRC_BONUS_DIR		= ./checker_bonus/src_bonus
# GNL_BONUS_DIR		= ./checker_bonus/gnl_bonus
# INCLUDES_BONUS_DIR	= ./checker_bonus/includes_bonus

# ══ Library Archives ════════════════════════════════════════════════════════ #
#    ----------------                                                          #

LIBFT_A				= ${LIBRARIES}/${LIBFT_DIR}/libft.a
PRINTFT_A			= ${LIBRARIES}/${PRINTFT_DIR}/libftprintf.a
EXAMFT_A			= ${LIBRARIES}/${EXAMFT_DIR}/libexamft.a
LIBMLX42_A			= ${MLX42_LIB}/libmlx42.a

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

CFLAGS 				= -Wall -Werror -Wextra
IFLAGS				= -I${INCLUDES_DIR} -I${MLX42_INCLUDE}
LFLAGS				= -L${LIBRARIES}/${LIBFT_DIR} -lft \
						-L${LIBRARIES}/${PRINTFT_DIR} -lftprintf \
						-L${LIBRARIES}/${EXAMFT_DIR} -lexamft \
						-L$(MLX42_LIB) -lmlx42 -lglfw -ldl -lm -lpthread

# ══ Flags Bonus══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

# IFLAGS_BONUS		= -I${INCLUDES_BONUS_DIR}

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

SRC 				= ${SRC_DIR}/fdf.c

GNL					= ${LIBRARIES}/${GNL_DIR}/get_next_line.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_utils.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_bonus.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_utils_bonus.c

ERR					= ${ERRORS_DIR}/ft_manage_err.c

INT					= ${INIT_DIR}/ft_init.c \
						${INIT_DIR}/ft_init_map.c

UTL					= ${UTILS_DIR}/ft_absolute.c \
						${UTILS_DIR}/ft_collect_z_minmax.c \
						${UTILS_DIR}/ft_complete_matrix.c \
						${UTILS_DIR}/ft_count_words.c \
						${UTILS_DIR}/ft_get_min.c \
						${UTILS_DIR}/ft_matrix_height.c \
						${UTILS_DIR}/ft_matrix_width.c \
						${UTILS_DIR}/ft_swapping.c \
						${UTILS_DIR}/ft_part.c

PRP					= ${PERIPHERALS_DIR}/ft_keyboard.c

CTL					= ${CONTROL_DIR}/ft_check_commas.c \
						${CONTROL_DIR}/ft_control_args.c \
						${CONTROL_DIR}/ft_control_fd.c \
						${CONTROL_DIR}/ft_control_map.c \
						${CONTROL_DIR}/ft_ext_valid.c

DRW					= ${DRAW_DIR}/ft_cam_init.c \
						${DRAW_DIR}/ft_draw.c \
						${DRAW_DIR}/ft_get_color.c \
						${DRAW_DIR}/ft_manage_hook.c \
						${DRAW_DIR}/ft_project_iso.c \
						${DRAW_DIR}/ft_put_pixel.c \
						${DRAW_DIR}/ft_reset_angles.c

FRE					= ${FREE_DIR}/ft_cleanup.c \
						${FREE_DIR}/ft_free_fdf.c \
						${FREE_DIR}/ft_free_inner.c \
						${FREE_DIR}/ft_free_map.c \
						${FREE_DIR}/ft_free_split.c \
						${FREE_DIR}/ft_free_superarray.c

OBJ_SRC				= $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})
OBJ_GNL				= $(patsubst ${LIBRARIES}/${GNL_DIR}/%.c, ${OBJ_DIR}/%.o, \
						${GNL})
OBJ_ERR				= $(patsubst ${ERRORS_DIR}/%.c, ${OBJ_DIR}/%.o, ${ERR})
OBJ_INT				= $(patsubst ${INIT_DIR}/%.c, ${OBJ_DIR}/%.o, ${INT})
OBJ_UTL				= $(patsubst ${UTILS_DIR}/%.c, ${OBJ_DIR}/%.o, ${UTL})
OBJ_CTL				= $(patsubst ${CONTROL_DIR}/%.c, ${OBJ_DIR}/%.o, ${CTL})
OBJ_DRW				= $(patsubst ${DRAW_DIR}/%.c, ${OBJ_DIR}/%.o, ${DRW})
OBJ_FRE				= $(patsubst ${FRE_DIR}/%.c, ${OBJ_DIR}/%.o, ${FRE})
OBJ_PRP				= $(patsubst ${PERIPHERALS_DIR}/%.c, ${OBJ_DIR}/%.o, \
						${PRP})

# ══ Sources Bonus ═══════════════════════════════════════════════════════════ #
#    -------------                                                             #

# SRC_BONUS			= ${SRC_BONUS_DIR}/checker_bonus.c
# GNL_BONUS			= ${GNL_BONUS_DIR}/get_next_line_bonus.c \
# 						${GNL_BONUS_DIR}/get_next_line_utils_bonus.c

# OBJ_SRC_BONUS		= $(patsubst ${SRC_BONUS_DIR}/%.c, ${OBJ_DIR}/%.o, \
# 						${SRC_BONUS})
# OBJ_GNL_BONUS		= $(patsubst ${GNL_BONUS_DIR}/%.c, ${OBJ_DIR}/%.o, \
# 						${GNL_BONUS})

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME}

${NAME}: ftlibft ftprintf ftexamft ${LIBMLX42_A} ${OBJ_SRC} ${OBJ_GNL} \
									${OBJ_ERR} ${OBJ_INT} ${OBJ_UTL} \
									${OBJ_CTL} ${OBJ_DRW} ${OBJ_FRE} \
									${OBJ_PRP}
	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJ_SRC} ${OBJ_GNL} ${OBJ_ERR} \
									${OBJ_INT} ${OBJ_UTL} ${OBJ_CTL} \
									${OBJ_DRW} ${OBJ_FRE} ${OBJ_PRP} \
									${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${LIBRARIES}/${GNL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${ERRORS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${INIT_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${UTILS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${CONTROL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${DRAW_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${FREE_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${PERIPHERALS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

ftlibft:
	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} all

ftprintf:
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} all

ftexamft:
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} all

# bonus: ${NAME_BONUS}

# ${NAME_BONUS}: ftlibft ftprintf ftexamft ${OBJ_ERR} ${OBJ_INT} \
# 											${OBJ_MOV} ${OBJ_SRT} ${OBJ_UTL} \
# 											${OBJ_SRC_BONUS} ${OBJ_GNL_BONUS}
# 	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
# 	@${CC} ${CFLAGS} ${IFLAGS} ${IFLAGS_BONUS} -o ${NAME_BONUS} \
# 			${OBJ_ERR} ${OBJ_INT} ${OBJ_MOV} ${OBJ_SRT} ${OBJ_UTL} \
# 			${OBJ_SRC_BONUS} ${OBJ_GNL_BONUS} ${LFLAGS} ${IFLAGS_BONUS}
# 	@echo "$(GREEN) $(NAME_BONUS) all created ✓$(DEF_COLOR)"

# ${OBJ_DIR}/%.o: ${SRC_BONUS_DIR}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

# ${OBJ_DIR}/%.o: ${GNL_BONUS_DIR}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
	@echo "$(YELLOW)Removing object files ...$(DEF_COLOR)"

	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} clean
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} clean
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} clean
	@$(RM) ${OBJ_DIR}/*.o

	@echo "$(RED)Object files removed $(DEF_COLOR)"

fclean:	clean
	@echo "$(YELLOW)Removing binaries ...$(DEF_COLOR)"

	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} fclean
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} fclean
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} fclean
	@${RM} ${NAME} ${NAME_BONUS}

	@echo "$(RED)Binaries removed $(DEF_COLOR)"

re:	fclean all

.PHONY : all ftlibft ftprintf ftexamft clean fclean bonus re
