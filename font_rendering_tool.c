#include <stdio.h>
#include <gtk/gtk.h>
 
#define MAX_TEXT_LEN 5000
char text_buffer[MAX_TEXT_LEN] = "";
char text_buffer2[MAX_TEXT_LEN] = "";
const gchar test_text[] = "Hello World!\nHere I am";
const gchar test_text2[] = "Sudip Shil";
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
	GtkWidget *table, *label, *picker1, *picker2;
	GtkWidget *boxb1;
	GtkWidget *boxb2;
	GtkWidget *dmyl1;//left
	GtkWidget *dmyr1;//right
	GtkWidget *dmyu1;//upper
	GtkWidget *dmyb1;//bottom
	GtkWidget *dmyc1;//center
        const gchar font1[] = "C059 Bold Italic 40";
        const gchar font2[] = "C059 Bold 50";
	window = gtk_application_window_new(GTK_APPLICATION(app));
	gtk_window_set_title (GTK_WINDOW (window), "Font Comparison");
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);

	boxb1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 5);
	gtk_window_set_child (GTK_WINDOW (window), boxb1);

	dmyl1 = gtk_label_new(NULL); // dummy label for left space
				     //gtk_label_set_width_chars (GTK_LABEL (dmyl1), 50);
	gtk_widget_set_hexpand (dmyl1, TRUE);
	gtk_box_append (GTK_BOX (boxb1), dmyl1);


	boxb2 = gtk_box_new (GTK_ORIENTATION_VERTICAL, 10);
	gtk_box_append (GTK_BOX (boxb1), boxb2);


	dmyr1 = gtk_label_new(NULL); // dummy label for right space
				     //gtk_label_set_width_chars (GTK_LABEL (dmyr1), 50);
	gtk_widget_set_hexpand (dmyr1, TRUE);
	gtk_box_append (GTK_BOX (boxb1), dmyr1);


	dmyu1 = gtk_label_new(NULL); // dummy label for upper space 
	gtk_widget_set_vexpand (dmyu1, TRUE);
	gtk_box_append (GTK_BOX (boxb2), dmyu1);

	picker1 = gtk_font_button_new ();
        gtk_font_chooser_set_font(picker1, font1);
	gtk_box_append (GTK_BOX (boxb2), picker1);
	g_signal_connect(picker1, "font-set", G_CALLBACK(font_set_cb1), NULL);
	//gtk_widget_set_hexpand (picker1, FALSE);

	font_test_label1 = gtk_label_new (NULL);
	gtk_widget_set_halign (font_test_label1, GTK_ALIGN_START);
	gtk_widget_set_valign (font_test_label1, GTK_ALIGN_CENTER);
	//gtk_widget_set_hexpand (font_test_label1, TRUE);
	//gtk_widget_set_vexpand (font_test_label1, TRUE);
	gtk_box_append (GTK_BOX (boxb2), font_test_label1);
	set_test_label_text_and_font1(font1);

	dmyc1 = gtk_label_new(NULL); // dummy label for center space
	gtk_widget_set_vexpand (dmyc1, TRUE);
	gtk_box_append (GTK_BOX (boxb2), dmyc1);

	picker2 = gtk_font_button_new ();
        gtk_font_chooser_set_font(picker2, font2);
	gtk_box_append (GTK_BOX (boxb2), picker2); 
	g_signal_connect(picker2, "font-set", G_CALLBACK(font_set_cb2), NULL);
	// gtk_widget_set_hexpand (picker2, TRUE);

	font_test_label2 = gtk_label_new (NULL);
	gtk_widget_set_halign (font_test_label2, GTK_ALIGN_START);
	gtk_widget_set_valign (font_test_label2, GTK_ALIGN_CENTER);
	//gtk_widget_set_hexpand (font_test_label2, TRUE);
	//gtk_widget_set_vexpand (font_test_label2, TRUE);
	gtk_box_append (GTK_BOX (boxb2), font_test_label2);
	set_test_label_text_and_font2(font2);

	dmyb1 = gtk_label_new(NULL); // dummy label for bottom space
	gtk_widget_set_vexpand (dmyb1, TRUE);
	gtk_box_append (GTK_BOX (boxb2), dmyb1);


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
