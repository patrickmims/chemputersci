#include "cs.h"

void *create_node()
{
    void *node = NULL;

    if((node = malloc(sizeof(void *))) == NULL)
        fprintf(linkedlist_error_log(), "error: create_node()");

    puts("node created...");

    return node;
}

/**
 * Because I am using a nested structure: element, I have to call the values with:
 *
 * node->elem.id 
 * node->elem.automic_number
 *
 * ...
 */
// i want to pass a structure to this method instead of the params
// void insert(struct node **list, struct element *element)
void insert(struct node **list, int id, int atomic_number, char *symbol, char *name, char *slug, char *category)
{
    struct node *node = (struct node *)create_node();

    node->elem.id = id;
    node->elem.atomic_number = atomic_number;
    strncpy(node->elem.symbol, symbol, sizeof(node->elem.symbol));
    strncpy(node->elem.name, name, sizeof(node->elem.name));
    strncpy(node->elem.slug, slug, sizeof(node->elem.slug));
    strncpy(node->elem.category, category, sizeof(node->elem.category));
    /*
       strncpy(node->elem.category, category, sizeof(node->elem.category));
       strncpy(node->elem.block, category, sizeof(node->elem.block));
       node->elem.group_number = group_number;
       node->elem.period = period;
       strncpy(node->elem.electron_configuration, electron_configuration, sizeof(node->elem.electron_configuration));
       strncpy(node->elem.electron_configuration_semantic, electron_configuration_semantic, sizeof(node->elem.electron_configuration_semantic));

       strncpy(node->elem.electron_configuration_per_shell[], category, sizeof(node->elem.category));
       node->elem.atomic_mass= atomic_mass;
       node->elem.density = density;
       node->elem.melting_point = melting_point;
       node->elem.boiling_point = boiling_point;
       strncpy(node->elem.state_at_room_temp, state_at_room_temp, sizeof(node->elem.state_at_room_temp));
       strncpy(node->elem.appearance, appearance, sizeof(node->elem.appearance));
       node->elem.eletronegativity = eletronegativity;
       node->elem.ionization_energy = ionization_energy;
       node->elem.affinity = affinity;
       strncpy(node->elem.oxidation_states, oxidation_states, sizeof(node->elem.oxidation_states));
       node->elem.atomic_radius = atomic_radius;
       node->elem.covalent_radius = covalent_radius;
       node->elem.val_der_waals_radius = val_der_waals_radius;
       strncpy(node->elem.discovered_by, discovered_by, sizeof(node->elem.discovered_by));
       node->elem.discovery_year = discovery_year;
       strncpy(node->elem.discovery_location, discovery_location, sizeof(node->elem.discovery_location));
       strncpy(node->elem.category_color, category_color, sizeof(node->elem.category_color));
       strncpy(node->elem.cpk_hex_color, cpk_hex_color, sizeof(node->elem.cpk_hex_color));
       strncpy(node->elem.summary, summary, sizeof(node->elem.summary));
       strncpy(node->elem.description, description, sizeof(node->elem.description));
       strncpy(node->elem.uses, uses, sizeof(node->elem.uses));
       strncpy(node->elem.fun_fact, fun_fact, sizeof(node->elem.fun_fact));
       strncpy(node->elem.named_after, atomic_mass, sizeof(node->elem.atomic_mass));
       strncpy(node->elem.isotopes[], isotopes, sizeof(node->elem.isotopes));
       strncpy(node->elem.is_synthetic, is_synthetic, sizeof(node->elem.is_synthetic));
       strncpy(node->elem.is_radioactive, is_radioactive, sizeof(node->elem.is_radioactive));
       node->elem.grid_row = grid_row;
       node->elem.grid_column = grid_column;
    */

    node->next = *list;
    *list = node;

    printf(" %d\n %d\n %s\n %s\n %s\n %s\n", id, atomic_number, symbol, name, slug, category);
}
