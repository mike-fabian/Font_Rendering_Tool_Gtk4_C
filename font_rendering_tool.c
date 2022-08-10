#include <stdio.h>
#include <gtk/gtk.h>
 
#define MAX_TEXT_LEN 5000
char text_buffer[MAX_TEXT_LEN] = "";
char text_buffer2[MAX_TEXT_LEN] = "";
const gchar test_text[] = "\tHello World!";
const gchar test_text2[] = "\tSudip Shil";
GtkLabel *font_test_label1;
GtkLabel *font_test_label2;

static void set_test_label_text_and_font1(gchar *font_and_size)
{
    snprintf(text_buffer, MAX_TEXT_LEN - 1,
             "<span font=\"%s\">%s</span>",
             font_and_size, test_text);
    gtk_label_set_markup(font_test_label1, text_buffer);
                                  
}

static void set_test_label_text_and_font2(gchar *font_and_size)
{
    snprintf(text_buffer2, MAX_TEXT_LEN - 1,
             "<span font=\"%s\">%s</span>",
             font_and_size, test_text2);
    gtk_label_set_markup(font_test_label2, text_buffer2);
                                  
}

static void font_set_cb1 (GtkFontButton* button, gpointer user_data)
{
    const gchar *font_and_size = gtk_font_chooser_get_font(button);
    printf("%s\n", font_and_size);
    set_test_label_text_and_font1(font_and_size);
}

static void font_set_cb2 (GtkFontButton* button, gpointer user_data)
{
    const gchar *font_and_size = gtk_font_chooser_get_font(button);
    printf("%s\n", font_and_size);
    set_test_label_text_and_font2(font_and_size);
}

static void app_activate (GApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *table, *label, *picker;
    window = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title (GTK_WINDOW (window), "Pickers");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);

    table = gtk_grid_new ();
    gtk_widget_set_margin_start (table, 20);
    gtk_widget_set_margin_end (table, 20);
    gtk_widget_set_margin_top (table, 20);
    gtk_widget_set_margin_bottom (table, 20);
    gtk_grid_set_row_spacing (GTK_GRID (table), 3);
    gtk_grid_set_column_spacing (GTK_GRID (table), 10);
    gtk_window_set_child (GTK_WINDOW (window), table);

  /*  
    label = gtk_label_new (NULL);
    gtk_label_set_markup(GTK_WIDGET(label), "<span font=\"18\" color=\"Blue\"><b>Font 1:</b></span>");
    gtk_widget_set_halign (label, GTK_ALIGN_START);
    gtk_widget_set_valign (label, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand (label, TRUE);
    gtk_grid_attach (GTK_GRID (table), label, 0, 1, 1, 1);
*/
    picker = gtk_font_button_new ();
    //gtk_grid_attach (GTK_GRID (table), picker, 1, 1, 1, 1);
    gtk_grid_attach (GTK_GRID (table), picker, 0, 1, 1, 1);
    g_signal_connect(picker, "font-set", G_CALLBACK(font_set_cb1), NULL);


    font_test_label1 = gtk_label_new (NULL);
    gtk_widget_set_halign (font_test_label1, GTK_ALIGN_START);
    gtk_widget_set_valign (font_test_label1, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand (font_test_label1, TRUE);
    gtk_widget_set_vexpand (font_test_label1, TRUE);
    //gtk_grid_attach (GTK_GRID (table), GTK_WIDGET(font_test_label1), 1, -1, 1, 1);
    gtk_grid_attach (GTK_GRID (table), GTK_WIDGET(font_test_label1), 1, 1, 1, 1);
    set_test_label_text_and_font1("Sans Regular 25");


    //------------------------------------------------------------------------------------
/*
    label = gtk_label_new (NULL);
    gtk_label_set_markup(GTK_WIDGET(label), "<span font=\"18\" color=\"Blue\"><b>Font 2:</b></span>");
    gtk_widget_set_halign (label, GTK_ALIGN_START);
    gtk_widget_set_valign (label, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand (label, TRUE);
    gtk_grid_attach (GTK_GRID (table), label, 0, 3, 1, 1);
*/
    picker = gtk_font_button_new ();
    //gtk_grid_attach (GTK_GRID (table), picker, 1, 3, 1, 1);
    gtk_grid_attach (GTK_GRID (table), picker, 0, 3, 1, 1);
    g_signal_connect(picker, "font-set", G_CALLBACK(font_set_cb2), NULL);

   
    font_test_label2 = gtk_label_new (NULL);
    gtk_widget_set_halign (font_test_label2, GTK_ALIGN_START);
    gtk_widget_set_valign (font_test_label2, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand (font_test_label2, TRUE);
    gtk_widget_set_vexpand (font_test_label2, TRUE);
    //gtk_grid_attach (GTK_GRID (table), GTK_WIDGET(font_test_label2), 1, 2, 1, 1);
    gtk_grid_attach (GTK_GRID (table), GTK_WIDGET(font_test_label2), 1, 3, 1, 1);
    set_test_label_text_and_font2("Sans Regular 25");



   //------------------------------------------------------------------------------------
/*   
   label = gtk_label_new (NULL);
    gtk_label_set_markup(GTK_WIDGET(label), "<span font=\"18\" color=\"Blue\"><b>\n\nPango Two Font Description:</b></span>");
    gtk_widget_set_halign (label, GTK_ALIGN_START);
    gtk_widget_set_valign (label, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand (label, TRUE);
    gtk_grid_attach (GTK_GRID (table), label, 0, 4, 1, 1);

    GtkWidget *font_test_label3;
    font_test_label3 = gtk_label_new (NULL);
    gtk_label_set_markup(GTK_WIDGET(font_test_label3), "<span font=\"20\" color=\"Green\">|| Font Difference Described Here ||</span>");
    gtk_widget_set_halign (font_test_label3, GTK_ALIGN_START);
    gtk_widget_set_valign (font_test_label3, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand (font_test_label3, TRUE);
    gtk_widget_set_vexpand (font_test_label3, TRUE);
    gtk_grid_attach (GTK_GRID (table), GTK_WIDGET(font_test_label3), 0, 5, 1, 1);
*/

    gtk_widget_show (window);
}



int main(int argc, char **argv){
        GtkApplication *app;
        int status;
        app = gtk_application_new("org.gtk.example", G_APPLICATION_HANDLES_OPEN);
        g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);
        status = g_application_run(G_APPLICATION(app), argc, argv);
        g_object_unref(app);
        return status;}
