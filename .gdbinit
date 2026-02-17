define print_stacks
    printf "\nStack A (top->bottom): "
    set $n = (stack_a->first)
    while $n != 0
        printf "%d ", ($n->content)
        set $n = ($n->next)
    end
    printf "\nStack B (top->bottom): "
    set $n = (stack_b->first)
    while $n != 0
        printf "%d ", ($n->content)
        set $n = ($n->next)
    end
    printf "\n\n"
end
